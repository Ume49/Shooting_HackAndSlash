#pragma once
#include"Vector.h"

namespace Shooting_HackAndSlash {
	class Slot {
		Point leftup, rightdown, center;
	public:
		Slot(const Point& center, const Point& size);
		~Slot() = default;

		// マウスが触れているか
		bool is_on_mouse() const;

		// 中央座標を返す
		Point Center() const;

		void draw() const;
	};
}
