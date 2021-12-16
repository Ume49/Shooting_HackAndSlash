#pragma once
#include"Vector.h"
#include"eBullet.h"

namespace Shooting_HackAndSlash::Gun_Custamize {
	// マウスカーソルにくっついてくるアイコン
	class Dragged_Icon {
		Vec2 pos;
	public:
		eBullet bullet;

		virtual void update();
		virtual void draw() const;

		Dragged_Icon();
		Dragged_Icon(const eBullet& bullet);
		~Dragged_Icon() = default;
	};

	// 上記クラスのNull代替クラス
	class Dragged_Icon_Null : public Dragged_Icon {
	public:
		Dragged_Icon_Null() = default;
		~Dragged_Icon_Null() = default;

		void update() override {}
		void draw() const override{}
	};
}
