#include "BackGround_BigStar.h"

#include<DxLib.h>

#include"Time.h"

namespace {
	// 何角形で表現するのか
	constexpr int poly = 4;

	// 星のサイズ。大きいときと小さいとき
	constexpr float
		big_radius	 = 2.f,
		small_radius = 1.f;

	constexpr float interval   = 1.f;	// stateの切り替わる周期
	constexpr float count_init = 0.f;	// カウンター初期値
}

namespace Shooting_HackAndSlash::BackGround_Object {
	BigStar::BigStar() :
		position{},
		count{ ::count_init },
		color{},
		state{  }{
	}

	BigStar::BigStar(const Vec2& pos, const Color& c, float deray) :
		position{ pos },
		count{ ::count_init + deray },
		color{ c },
		state{  }{
	}

	void BigStar::update() {
		// カウンターが周期を超えていた場合
		if ((count += Time::DeltaTime()) >= ::interval) {
			// カウンターをリセット
			count = ::count_init;

			// stateを切り替え
			if (state == State::ON) {
				state = State::OFF;
			}
			else {
				state = State::ON;
			}
		}
	}

	void BigStar::draw() const {
#define SWITCH Shooting_HackAndSlash::BackGround_Object::BigStar::State

		switch (state) {
		case SWITCH::ON:
			DrawCircleAA(position.x, position.y, ::big_radius, ::poly, color);
			break;
		case SWITCH::OFF:
			DrawCircleAA(position.x, position.y, ::small_radius, ::poly, color);
			break;
		}
#undef SWITCH
	}
}