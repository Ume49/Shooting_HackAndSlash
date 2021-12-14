#include "MousePointer.h"

#include<algorithm>
#include<DxLib.h>

namespace Shooting_HackAndSlash::Input_Component {
	void MousePointer::update() {
		GetMousePoint(&pos.x, &pos.y);
		mouse_delta = pos - past_pos;
		past_pos = pos;
	}

	const Point& MousePointer::MousePos() const {
		return pos;
	}

	const Point& MousePointer::MouseDelta() const {
		return mouse_delta;
	}

	const Vec2 MousePointer::MousePosF() const {
		return Vec2(static_cast<float>(pos.x), static_cast<float>(pos.y));
	}

	MousePointer::MousePointer() :
		pos(),
		past_pos(0,0),
		mouse_delta()
	{
	}

	MousePointer::~MousePointer() {
	}
}