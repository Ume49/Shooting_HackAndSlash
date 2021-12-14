#include "Title.h"

#include<DxLib.h>
#include"PlayerInfo.h"
#include"Stage_Info.h"
#include"Define.h"

namespace Shooting_HackAndSlash::Scene {
	void Title::init() {
		buttons.Add([&]() { listener.SceneChange(eScene::Game, true); }, "Start", Point{ 300, 800 });
		buttons.Add([&]() {keep_game = false; }, "Quit", Point{ 300, 900 });

		PlayerInfo::initialize();
		Stage_Info::initialize();
	}

	bool Title::update() {
		buttons.update();

		return keep_game;
	}

	void Title::draw() const {
		DrawString(100, 100, title_text.c_str(), Palette::White);
		buttons.draw();
	}
}