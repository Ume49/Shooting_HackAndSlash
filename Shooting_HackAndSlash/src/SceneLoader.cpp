#include "SceneLoader.h"

#include"NullScene.h"
#include"MainGame.h"
#include"Boss.h"
#include"Result.h"
#include"Title.h"
#include"Menu.h"
#include"Debug_Choice.h"
#include"Debug_Scene.h"
#include"Scene_GunCustom.h"
#include"Volume_Set_Scene.h"

#include"Define.h"

namespace Shooting_HackAndSlash {
	namespace BACK = Define::Background;

	SceneLoader::SceneLoader() :
		scene_stack(),
		next{ eScene::Null, false },
		isSceneChange(false),
		isScenePop(false),
		isFade(false),
		cursor(),
		background_color(BACK::R, BACK::G, BACK::B){
		// 最下部にNullSceneを置いておく
		scene_stack.push(std::make_unique<Scene::NullScene>(*this));
#ifdef _DEBUG
		scene_stack.push(std::make_unique<Scene::Debug_Choice>(*this));
#else
		scene_stack.push(std::make_unique<Scene::Title>(*this));
#endif
	}

	bool SceneLoader::load() {
		// シーンを更新
		bool temp = scene_stack.top()->update();

		// 背景色を描画
		DrawBox(0, 0, Define::Window::WITDH, Define::Window::HEIGHT, background_color, TRUE);

		// シーンを描画
		scene_stack.top()->draw();

		// 全ての描画より後にカーソルを描画
		cursor.draw();

		// シーンスタック変更
		if (isScenePop) { scene_pop(); }
		if (isSceneChange) {
			if (isFade) {
				if (fade.update()) {
					isFade = false;
				}
			}
			else {
				scene_change();
			}
		}

		// ゲームをやめるかどうか通知
		return temp;
	}

	void SceneLoader::SceneChange(eScene next_scene, bool stack_clear, bool is_fade) {
		next.scene = next_scene;
		next.is_clear = stack_clear;
		isSceneChange = true;
		fade.Set();
		isFade = is_fade;
	}

	void SceneLoader::ScenePop() {
		isScenePop = true;
	}

	void SceneLoader::scene_change() {
		// リソースの無駄な解放を防ぐため、シーンスタックをクリアする前に次のシーンを作成する
		std::unique_ptr<AbstructScene> temp_scene;

		switch (next.scene) {
		default:
			temp_scene = std::make_unique<Scene::NullScene>(*this);
			break;
		case eScene::Game:
			temp_scene = std::make_unique<Scene::MainGame>(*this);
			break;
		case eScene::Menu:
			temp_scene = std::make_unique<Scene::Menu>(*this, *scene_stack.top());
			break;
		case eScene::Result:
			temp_scene = std::make_unique<Scene::Result>(*this, *scene_stack.top());
			break;
		case eScene::Title:
			temp_scene = std::make_unique<Scene::Title>(*this);
			break;
		case eScene::Boss:
			temp_scene = std::make_unique<Scene::Boss>(*this);
			break;
		case eScene::Gun_Custom:
			temp_scene = std::make_unique<Scene::GunCustom>(*this, *scene_stack.top());
			break;
		case eScene::Volume:
			temp_scene = std::make_unique<Scene::Volume_Set>(*this, *scene_stack.top());
			break;
		case eScene::Debug:
			temp_scene = std::make_unique<Scene::Debug_Scene>(*this);
			break;
		}

		// リセット
		if (next.is_clear) {
			// 長さを取得し、決定
			// -1 : 最下部に配置されているNullSceneを消さないようにするため
			size_t count = scene_stack.size() - 1;

			for (auto i = 0; i < count; i++) {
				scene_stack.pop();
			}
		}

		// 改めてコンテナに挿入する
		scene_stack.push(std::move(temp_scene));

		// シーン遷移完了
		isSceneChange = false;
	}

	void SceneLoader::scene_pop() {
		scene_stack.pop();

		// シーンスタックが空になってしまうことの回避
		if (scene_stack.empty()) {
			scene_stack.push(std::make_unique<Scene::NullScene>(*this));
		}

		isScenePop = false;
	}
}