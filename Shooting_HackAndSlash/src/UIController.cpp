#include "UIController.h"

#include"Define.h"

#include<DxLib.h>

#include"Player.h"

// UI
#include"HP_Bar.h"
#include"PlayerInfo.h"
#include"Kill_Count_Displayer.h"
#include"Stage_Num_Displayer.h"

namespace Shooting_HackAndSlash {
	UIController::UIController(Player& p) :
		draw_pos(),
		bomb(),
		ui_objects(),
		background(Define::Path::Photo::UI_Window)
	{
		ui_objects.reserve(10);

		ui_objects.push_back(std::make_unique<UI::HP_Bar>());
		ui_objects.push_back(std::make_unique<UI::Bullet_CoolTime_Displayer>(p.show_bulletlancher()));
		ui_objects.push_back(std::make_unique<UI::Kill_Count_Displayer>());
		ui_objects.push_back(std::make_unique<UI::Stage_Num_Displayer>());
	}

	void UIController::draw() const {
		DrawGraph(Define::Window::UI::Standerd::X, Define::Window::UI::Standerd::Y, background, TRUE);

		for (auto& w : ui_objects) {
			w->draw();
		}
	}
}