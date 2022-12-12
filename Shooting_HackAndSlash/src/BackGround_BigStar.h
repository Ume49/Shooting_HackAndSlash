#pragma once

#include"Vector.h"
#include"Color.h"

namespace Shooting_HackAndSlash::BackGround_Object {
	// �^�C�g����ʂŎg�p���� �_�ł��鐯
	class BigStar {
		Vec2 position;
		float count;
		Color color;

		enum class State {
			ON,		// ���邢
			OFF		// �Â�
		} state;
	public:
		 BigStar();
		 BigStar(const Vec2& pos, const Color& c, float deray = 0.f);
		~BigStar() = default;

		// �X�V���� ���t���[��1�񂾂��Ăяo��
		void update();
		// ����`�悷��
		void draw() const;
	};
}
