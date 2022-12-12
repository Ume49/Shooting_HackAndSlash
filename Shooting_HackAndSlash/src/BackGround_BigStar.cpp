#include "BackGround_BigStar.h"

#include<DxLib.h>

#include"Time.h"

namespace {
	// ���p�`�ŕ\������̂�
	constexpr int poly = 4;

	// ���̃T�C�Y�B�傫���Ƃ��Ə������Ƃ�
	constexpr float
		big_radius	 = 2.f,
		small_radius = 1.f;

	constexpr float interval   = 1.f;	// state�̐؂�ւ�����
	constexpr float count_init = 0.f;	// �J�E���^�[�����l
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