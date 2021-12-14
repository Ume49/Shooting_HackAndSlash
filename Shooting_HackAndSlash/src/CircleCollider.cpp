#include "CircleCollider.h"

#include<DxLib.h>
#include"Define.h"

namespace Shooting_HackAndSlash {
	void CircleCollider::draw() const {
		DrawCircleAA(pos.x, pos.y, radius, 12, Palette::Collider, FALSE);
	}

	bool CircleCollider::isColide(const CircleCollider& r) {
		float distance = pos.distance(r.pos);
		float boarder = radius + r.radius;

		return distance <= boarder;
	}
}