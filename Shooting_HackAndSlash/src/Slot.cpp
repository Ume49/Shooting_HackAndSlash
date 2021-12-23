#include"Slot.h"

#include"Input.h"

#include"Define.h"

namespace Shooting_HackAndSlash {
	Slot::Slot(const Point& c, const Point& size) :
		leftup(),
		rightdown(),
		center(c)
	{
		Point half = size / 2;

		leftup = center - half;
		rightdown = center + half;
	}

	bool Slot::is_on_mouse() const {
		Point mouse = Input::GetMousePos();

		bool result = true;

		// 範囲内にいるかどうか返す
		auto is_inrange = [](int value, int min, int max) {
			return (min <= value && value <= max);
		};

		// x軸方向において範囲内にいるかどうか
		result &= is_inrange(mouse.x, leftup.x, rightdown.x);

		// y軸方向において範囲内にいるかどうか
		result &= is_inrange(mouse.y, leftup.y, rightdown.y);

		return result;
	}

	Point Slot::Center() const {
		return center;
	}

	void Slot::draw() const {
#ifdef _DEBUG
		DrawBox(leftup.x, leftup.y, rightdown.x, rightdown.y, Palette::Collider, FALSE);
#endif // _DEBUG
	}
}