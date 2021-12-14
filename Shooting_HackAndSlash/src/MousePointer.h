#pragma once
#include"Vector.h"

namespace Shooting_HackAndSlash {
	namespace Input_Component {
		// �}�E�X�|�C���^�[�̈ʒu���Ď�����N���X
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