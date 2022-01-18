#include "HP_Bar.h"

#include"PlayerInfo.h"
#include"Define.h"
#include<DxLib.h>
#include<format>

#include"Define_Debug.h"

namespace {
	constexpr int POS_X = Shooting_HackAndSlash::Define::Window::UI::Standerd::X + 20;
	constexpr int POS_Y = Shooting_HackAndSlash::Define::Window::UI::End::Y - 280;
}

namespace Shooting_HackAndSlash {
	namespace UI {
		HP_Bar::HP_Bar() :
			now_hp(PlayerInfo::getInstance().hp),
			max_hp(PlayerInfo::getInstance().max_hp),
			gauge(Define::Path::Photo::HP_Bar::Gauge, Point{ ::POS_X, ::POS_Y }),
			frame_handle(Define::Path::Photo::HP_Bar::Frame),
			backgr_handle(Define::Path::Photo::HP_Bar::Back),
			Abstruct_UI(Point{ ::POS_X, ::POS_Y }),
			font_handle("Resource/Dot_24.dft"),
			mini_font_handle("Resource/Dot_16.dft")
		{
		}

		float HP_Bar::get_ratio() const {
			float rate = static_cast<float>(now_hp) / static_cast<float>(max_hp);

			if (rate < 0.f) return 0.f;

			return rate;
		}

		void HP_Bar::draw() const {
			auto draw = [&](int handle) { DrawGraph(pos.x, pos.y, handle, TRUE); };

			draw(backgr_handle);
			gauge.draw(get_ratio());
			draw(frame_handle);

#ifdef _DEBUG
			DrawStringToHandle(pos.x, pos.y - 30, "HP", Palette::Black, font_handle);
			DrawStringToHandle(pos.x + 10, pos.y + 232, std::format("{}/{}", now_hp, max_hp).c_str(), Palette::Black, mini_font_handle);
#endif // _DEBUG
		}
	}
}