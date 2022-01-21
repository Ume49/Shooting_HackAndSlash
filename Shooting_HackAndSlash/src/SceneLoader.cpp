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
		// �ŉ�����NullScene��u���Ă���
		scene_stack.push(std::make_unique<Scene::NullScene>(*this));
#ifdef _DEBUG
		scene_stack.push(std::make_unique<Scene::Debug_Choice>(*this));
#else
		scene_stack.push(std::make_unique<Scene::Title>(*this));
#endif
	}

	bool SceneLoader::load() {
		// �V�[�����X�V
		bool temp = scene_stack.top()->update();

		// �w�i�F��`��
		DrawBox(0, 0, Define::Window::WITDH, Define::Window::HEIGHT, background_color, TRUE);

		// �V�[����`��
		scene_stack.top()->draw();

		// �S�Ă̕`�����ɃJ�[�\����`��
		cursor.draw();

		// �V�[���X�^�b�N�ύX
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

		// �Q�[������߂邩�ǂ����ʒm
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
		// ���\�[�X�̖��ʂȉ����h�����߁A�V�[���X�^�b�N���N���A����O�Ɏ��̃V�[�����쐬����
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

		// ���Z�b�g
		if (next.is_clear) {
			// �������擾���A����
			// -1 : �ŉ����ɔz�u����Ă���NullScene�������Ȃ��悤�ɂ��邽��
			size_t count = scene_stack.size() - 1;

			for (auto i = 0; i < count; i++) {
				scene_stack.pop();
			}
		}

		// ���߂ăR���e�i�ɑ}������
		scene_stack.push(std::move(temp_scene));

		// �V�[���J�ڊ���
		isSceneChange = false;
	}

	void SceneLoader::scene_pop() {
		scene_stack.pop();

		// �V�[���X�^�b�N����ɂȂ��Ă��܂����Ƃ̉��
		if (scene_stack.empty()) {
			scene_stack.push(std::make_unique<Scene::NullScene>(*this));
		}

		isScenePop = false;
	}
}