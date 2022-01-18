#include "Title.h"

#include<DxLib.h>
#include"Define.h"

#include"PlayerInfo.h"
#include"Stage_Info.h"
#include"Gun_Info.h"
#include"Inventory_Info.h"

namespace {
	constexpr int 
		logo_pos_x = Shooting_HackAndSlash::Define::Window::Center::X,
		logo_pos_y = 380;
}

namespace Shooting_HackAndSlash::Scene {
	Title::Title(ISceneChangeListener& s) :
		AbstructScene(s), 
		title_text("Resource/ÉçÉS.png"),
		buttons(),
		keep_game(true) {
		buttons.Add([&]() { listener.SceneChange(eScene::Game, true); }, "Start", Point{ 300, 800 });
		buttons.Add([&]() {keep_game = false; }, "Quit", Point{ 300, 900 });

		PlayerInfo::initialize();
		Stage_Info::initialize();
		Gun_Info::initialize();
		Inventory_Info::initialize();
	}

	bool Title::update() {
		buttons.update();

		return keep_game;
	}

	void Title::draw() const {
		DrawRotaGraph(::logo_pos_x, ::logo_pos_y, Define::RotaGraph_Default::ExRate, Define::RotaGraph_Default::Angle, title_text, TRUE);
		buttons.draw();
	}
}