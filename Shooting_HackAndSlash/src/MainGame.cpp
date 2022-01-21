#include "MainGame.h"

#include<format>

#include"Input.h"
#include"Stage_Info.h"

#include"Define.h"
#include"Define_Debug.h"

#include<DxLib.h>

namespace {
	using namespace Shooting_HackAndSlash;

	const eScene clearscene = eScene::Game;
	constexpr bool scenechage_isclear = false;
	constexpr bool scenechage_isfade = true;

	const std::string bgm_path = "Resource/魔王魂  サイバー44.mp3";
}

namespace Shooting_HackAndSlash::Scene {
	MainGame::MainGame(ISceneChangeListener& s) : AbstructScene(s),
		ui(player),
		item_controller(player),
		enemy_controller(player, item_controller),
		bullet_player(enemy_controller),
		player(bullet_player, [&]() {listener.SceneChange(eScene::Result); }),
		enemy_spawner(player, enemy_controller) ,
		bgm(::bgm_path)
	{
		// ステージ情報に、新しいステージに入ったことを報告
		Stage_Info::Set_Stage_Next();
		// ステージクリア関数をセット
		Stage_Info::SetStageClearFunc([&]() {
			listener.SceneChange(::clearscene, ::scenechage_isclear, ::scenechage_isfade);
			});

		// BGM再生
		bgm.play();
	}

	MainGame::~MainGame() = default;

	bool MainGame::update() {
		// Escapeキーを押したらメニュー画面を開く
		if (Input::GetDown(Inputcode::Esc)) {
			listener.SceneChange(eScene::Menu);
		}

		// Tabを押したら銃カスタマイズ画面を開く
		if (Input::GetDown(Inputcode::Tab)) {
			listener.SceneChange(eScene::Gun_Custom);
		}

		star.update();

		player.update();
		bullet_player.update();
		item_controller.update();
		enemy_controller.update();
		enemy_spawner.update();

		return true;
	}

	void MainGame::draw() const {
#ifdef _DEBUG
		// マウス座標を描画
		Point p = Input::GetMousePos();
		DrawString(10, Define::Window::HEIGHT - 30, std::format("{},{}", p.x, p.y).c_str(), Palette::White);
#endif // _DEBUG

		star.draw();

		bullet_player.draw();
		item_controller.draw();
		player.draw();
		enemy_controller.draw();
		ui.draw();
	}
}