#pragma once
#include"Vector.h"

namespace Shooting_HackAndSlash {
	namespace Input_Component {
		// マウスポインターの位置を監視するクラス
		class MousePointer {
		private:
			Point pos, past_pos, mouse_delta;
		public:
			void update();
			const Point& MousePos() const;
			const Point& MouseDelta() const;
			const Vec2 MousePosF() const;
			MousePointer();
			~MousePointer();
		};
	}
}