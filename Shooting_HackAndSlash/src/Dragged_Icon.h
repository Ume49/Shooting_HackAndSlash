#pragma once
#include"Vector.h"
#include"eBullet.h"

namespace Shooting_HackAndSlash::Gun_Custamize {
	// マウスカーソルにくっついてくるアイコン
	class Dragged_Icon {
		Vec2 pos;
	public:
		eBullet bullet;

		void update();
		void draw() const;

		Dragged_Icon(const eBullet& bullet);
		~Dragged_Icon() = default;
	};
}
