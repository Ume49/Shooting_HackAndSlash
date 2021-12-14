#pragma once
#include"Photo_SharedHandle.h"
#include"Vector.h"

namespace Shooting_HackAndSlash {
	class CursorDrawer{
	private:
		Photo_SharedHandle photo;
		Vec2 size;
	public:
		void draw() const;

		CursorDrawer();
		~CursorDrawer();
	};
}
