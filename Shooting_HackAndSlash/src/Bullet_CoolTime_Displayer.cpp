#include "Bullet_CoolTime_Displayer.h"

#include"Define.h"
#include<DxLib.h>

namespace {
	using namespace Shooting_HackAndSlash;

	constexpr int x = Define::Window::UI::Standerd::X + 20;
	constexpr int y = Define::Window::UI::Standerd::Y + 120;
}

namespace Shooting_HackAndSlash::UI {
	Bullet_CoolTime_Displayer::Bullet_CoolTime_Displayer(const Bullet_Lancher& b) :
		Abstruct_UI(Point{ ::x, ::y }),
		bullet_lancher(b),
		gauge(Define::Path::Photo::Bullet_Gauge::Gauge, pos),
		frame_handle(Define::Path::Photo::Bullet_Gauge::Frame),
		backgr_handle(Define::Path::Photo::Bullet_Gauge::Back)
	{
	}

	void Bullet_CoolTime_Displayer::draw() const {
		// ÉQÅ[ÉWÇ…ìnÇ∑ó ÇåvéZ
		float value = 1.f - (bullet_lancher.show_cooltime() / bullet_lancher.show_max_cooltime());

		// ï`âÊä÷êî
		auto draw = [&](int handle) { DrawGraph(pos.x, pos.y, handle, TRUE); };
		
		draw(backgr_handle);
		gauge.draw(value);
		draw(frame_handle);
	}
}