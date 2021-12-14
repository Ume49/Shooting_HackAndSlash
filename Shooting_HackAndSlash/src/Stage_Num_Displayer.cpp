#include "Stage_Num_Displayer.h"
#include<DxLib.h>
#include<format>
#include"Stage_Info.h"
#include"Define.h"

namespace Shooting_HackAndSlash::UI {
	Stage_Num_Displayer::Stage_Num_Displayer() :
		Abstruct_UI(Point{0,0}),
		font_handle(Font_Test::Name, 16, 1, Font_Test::Type) {
	}

	void Stage_Num_Displayer::draw() const {
		DrawStringToHandle(pos.x, pos.y, std::format("ステージ:{}", Stage_Info::Show_Stage_Num()).c_str(), Palette::White, font_handle);
	}
}