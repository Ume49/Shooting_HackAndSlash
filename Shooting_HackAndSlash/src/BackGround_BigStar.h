#pragma once

#include"Vector.h"
#include"Color.h"

namespace Shooting_HackAndSlash::BackGround_Object {
	/**
	 * @brief �^�C�g����ʂŕ\������A���ł��鐯
	 * @sa Color
	 */
	class BigStar {
		Vec2 position;
		float count;
		Color color;

		enum class State {
			ON, OFF
		} state;
	public:
		BigStar();
		BigStar(const Vec2& pos, const Color& c, float deray = 0.f);
		~BigStar() = default;

		/**
		 * @brief �X�V����
		 */
		void update();
		/**
		 * @brief �`�揈��
		 */
		void draw() const;
	};
}
