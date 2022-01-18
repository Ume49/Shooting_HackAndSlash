#include "Stage_Num_Displayer.h"
#include<DxLib.h>
#include<format>
#include"Stage_Info.h"
#include"Define.h"

namespace {
	constexpr int
		pos_x = 10,
		pos_y = 10;

	constexpr int color = 0x7fff00;
}

namespace Shooting_HackAndSlash::UI {
	Stage_Num_Displayer::Stage_Num_Displayer() :
		Abstruct_UI(Point{::pos_x, ::pos_y}),
		font_handle("Resource/Dot_16.dft") {
	}

	void Stage_Num_Displayer::draw() const {
		DrawStringToHandle(pos.x, pos.y, std::format("ステージ:{}", Stage_Info::Show_Stage_Num()).c_str(), ::color, font_handle);
	}
}