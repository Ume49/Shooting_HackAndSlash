#include "BulletIcon.h"
#include"Input.h"
#include<DxLib.h>

namespace {
	// 拡大率 1.0倍
	constexpr double ExRate_Nomal = 1.;
	// 回転 DrawGraphと同じ結果になるような値
	constexpr double Zero_Angle = 0.;
}

namespace Shooting_HackAndSlash::Gun_Custamize {
	BulletIcon::BulletIcon(const std::string& path) :
		pos(),
		photo(path) {
		pos = Input::GetMousePosf();
	}

	void BulletIcon::update() {
		pos = Input::GetMousePosf();
	}

	void BulletIcon::draw() const {
		DrawRotaGraphF(pos.x, pos.y, ::ExRate_Nomal, ::Zero_Angle, photo, TRUE);
	}
}