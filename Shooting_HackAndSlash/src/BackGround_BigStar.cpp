#include "BackGround_BigStar.h"

#include<DxLib.h>

#include"Time.h"

namespace {
	// ���p�`�ŕ\������̂�
	constexpr int poly = 4;

	constexpr float
		big_radius = 2.f,
		small_radius = 1.f;

	// state�̐؂�ւ�����
	constexpr float interval = 1.f;

	// �J�E���^�[�����l
	constexpr float count_init = 0.f;
}

namespace Shooting_HackAndSlash::BackGround_Object {
	BigStar::BigStar() :
		position{},
		count{ ::count_init },
		color{},
		state{  }{
	}

	BigStar::BigStar(const Vec2& pos, const Color& c) :
		position{ pos },
		count{ ::count_init },
		color{ c },
		state{  }{
	}

	void BigStar::update() {
		// �J�E���^�[�������𒴂��Ă����ꍇ
		if ((count += Time::DeltaTime()) >= ::interval) {
			// �J�E���^�[�����Z�b�g
			count = ::count_init;

			// state��؂�ւ�
			if (state == State::ON) {
				state = State::OFF;
			}
			else {
				state = State::ON;
			}
		}
	}

	void BigStar::draw() const {
		switch (state) {
		case Shooting_HackAndSlash::BackGround_Object::BigStar::State::ON:
			DrawCircleAA(position.x, position.y, ::big_radius, ::poly, color);
			break;
		case Shooting_HackAndSlash::BackGround_Object::BigStar::State::OFF:
			DrawCircleAA(position.x, position.y, ::small_radius, ::poly, color);
			break;
		}
	}
}