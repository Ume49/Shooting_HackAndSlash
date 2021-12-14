#pragma once

#include"Vector.h"

namespace Shooting_HackAndSlash {
	class AbstructGameObject {
	public:
		Vec2 pos;

		virtual void fastupdate() {};
		virtual void update() {};
		virtual void lateupdate() {};
		virtual void draw() const = 0;
		AbstructGameObject() : pos() {}
		virtual ~AbstructGameObject() = default;
	};
}