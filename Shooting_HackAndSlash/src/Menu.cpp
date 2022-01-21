#include "Menu.h"
#include<DxLib.h>
#include"Input.h"
#include"Define.h"

namespace Shooting_HackAndSlash::Scene {
	Menu::Menu(ISceneChangeListener& s, const AbstructScene& back) :
		AbstructScene(s),
		buttons(),
		keep_game(true),
		back_scene(back),
		back_screen(Define::Path::Photo::BackScreen){
		// ボタンを追加
		buttons.Add([&]() { listener.SceneChange(eScene::Volume); },  "Volume", Point{ 334, 400 });
		buttons.Add([&]() { listener.ScenePop(); }, "Return", Point{ 334, 500 });
		buttons.Add([&]() { listener.SceneChange(eScene::Title, true); }, "goTitle", Point{ 334,600 });
		buttons.Add([&]() { keep_game = false; }, "Quit", Point{ 334, 700 });

		// 一時的にマウスポインタが外側に行けるようにする
		SetValidMousePointerWindowOutClientAreaMoveFlag(TRUE);
	}

	Menu::~Menu() {
		// マウスが外に出ないように戻す
		SetValidMousePointerWindowOutClientAreaMoveFlag(FALSE);
	}

	bool Menu::update() {
		buttons.update();

		// Escを押したら前のシーンに戻る
		if (Input::GetDown(Inputcode::Esc)) {
			listener.ScenePop();
		}

		return keep_game;
	}

	void Menu::draw() const {
		back_scene.draw();
		DrawGraph(0, 0, back_screen, TRUE);
		buttons.draw();
	}
}