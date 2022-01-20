#pragma once

#include"Vector.h"
#include"Color.h"

namespace Shooting_HackAndSlash::BackGround_Object {
	class BigStar {
		Vec2 position;
		float count;
		Color color;

		enum class State {
			ON, OFF
		} state;
	public:
		BigStar();
		BigStar(const Vec2& pos, const Color& c);
		~BigStar() = default;

		void update();
		void draw() const;
	};
}
