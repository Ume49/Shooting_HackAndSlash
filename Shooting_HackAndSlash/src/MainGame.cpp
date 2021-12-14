#include "MainGame.h"
#include"Input.h"
#include"Define.h"
#include<format>
#include"Stage_Info.h"

#include"Define_Debug.h"

namespace {
	using namespace Shooting_HackAndSlash;

	const eScene clearscene = eScene::Game;
	constexpr bool scenechage_isclear = false;
	constexpr bool scenechage_isfade = true;
}

namespace Shooting_HackAndSlash::Scene {
	bool MainGame::update() {
		// Escape�L�[���������烁�j���[��ʂ��J��
		if (Input::GetDown(Inputcode::Esc)) {
			listener.SceneChange(eScene::Menu);
		}

		player.update();
		bullet_player.update();
		item_controller.update();
		enemy_controller.update();
		enemy_spawner.update();
		
		return true;
	}

	void MainGame::draw() const {
#ifdef _DEBUG
		// �}�E�X���W��`��
		Point p = Input::GetMousePos();
		DrawString(10, Define::Window::HEIGHT-30, std::format("{},{}", p.x, p.y).c_str(), Palette::White);
#endif // _DEBUG

		bullet_player.draw();
		item_controller.draw();
		player.draw();
		enemy_controller.draw();
		ui.draw();
	}

	MainGame::MainGame(ISceneChangeListener& s) : AbstructScene(s),
		ui(player),
		item_controller(player),
		enemy_controller(player, item_controller),
		bullet_player(enemy_controller),
		player(bullet_player, [&]() {listener.SceneChange(eScene::Result); }),
		enemy_spawner(player, enemy_controller) {
		// �X�e�[�W���ɁA�V�����X�e�[�W�ɓ��������Ƃ��
		Stage_Info::Set_Stage_Next();
		// �X�e�[�W�N���A�֐����Z�b�g
		Stage_Info::SetStageClearFunc([&]() {listener.SceneChange(::clearscene, ::scenechage_isclear, ::scenechage_isfade); });
	}
}