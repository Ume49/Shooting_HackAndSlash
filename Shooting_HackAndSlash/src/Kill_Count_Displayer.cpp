#include "Kill_Count_Displayer.h"
#include"Stage_Info.h"
#include<DxLib.h>
#include<format>
#include"Define.h"

#include"Define_Debug.h"

namespace {
	using namespace Shooting_HackAndSlash;

	constexpr int x = Define::Window::UI::Standerd::X + 7;
	constexpr int y = Define::Window::UI::Standerd::Y + 70;

	constexpr int color = 0x000000;
}

namespace Shooting_HackAndSlash::UI {
#ifdef _DEBUG
	Kill_Count_Displayer::Kill_Count_Displayer() :
		font_handle("Resource/Dot_24.dft") {
		pos = Point{ ::x, ::y };
	}
#endif

	Kill_Count_Displayer::Kill_Count_Displayer(const std::string& path) :
		font_handle(path) {
		pos = Point{ ::x ,::y };
	}

	void Kill_Count_Displayer::draw() const {
		DrawStringToHandle(pos.x, pos.y, std::format("Žc‚è: {}", Stage_Info::Show_Remaining()).c_str(), ::color , font_handle);
	}
}