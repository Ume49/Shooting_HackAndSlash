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

	struct Set { Vec2 pos; unsigned int color; float deray; };

	const std::vector<Set> star_preset{
		Set{Vec2{ 594,728 }, 0xffffff, 0.f},
		Set{Vec2{ 213,813 }, 0xffffff, 0.1f},
		Set{Vec2{ 646,241 }, 0xffffff, 0.f},
		Set{Vec2{ 39 ,182 }, 0xffffff, 0.f},
		Set{Vec2{ 379,663 }, 0xffffff, 0.7f}
	};
}

namespace Shooting_HackAndSlash::Scene {
	Title::Title(ISceneChangeListener& s) :
		AbstructScene(s),
		title_text("Resource/ÉçÉS.png"),
		buttons(),
		keep_game(true) {
		// É{É^Éììoò^
		buttons.Add([&]() { listener.SceneChange(eScene::Game, true); }, "Start", Point{ 300, 800 });
		buttons.Add([&]() { keep_game = false; }, "Quit", Point{ 300, 900 });
		buttons.Add([&]() { listener.SceneChange(eScene::Volume); },  "Volume", Point{300, 700});

		// êØìoò^
		for (auto& w : ::star_preset) { stars.push_back(BackGround_Object::BigStar(w.pos, w.color, w.deray)); }

		// ÉVÉìÉOÉãÉgÉìÉNÉâÉXèâä˙âª
		PlayerInfo    ::initialize();
		Stage_Info	  ::initialize();
		Gun_Info      ::initialize();
		Inventory_Info::initialize();
	}

	bool Title::update() {
		for (auto& w : stars) { w.update(); }

		buttons.update();

		return keep_game;
	}

	void Title::draw() const {
		for (auto& w : stars) { w.draw(); }
		DrawRotaGraph(::logo_pos_x, ::logo_pos_y, Define::RotaGraph_Default::ExRate, Define::RotaGraph_Default::Angle, title_text, TRUE);
		buttons.draw();
	}
}