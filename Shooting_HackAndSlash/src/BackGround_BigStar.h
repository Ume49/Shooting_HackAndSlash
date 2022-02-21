#pragma once

#include"Vector.h"
#include"Color.h"

namespace Shooting_HackAndSlash::BackGround_Object {
	/**
	 * @brief タイトル画面で表示する、明滅する星
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
		 * @brief 更新処理
		 */
		void update();
		/**
		 * @brief 描画処理
		 */
		void draw() const;
	};
}
