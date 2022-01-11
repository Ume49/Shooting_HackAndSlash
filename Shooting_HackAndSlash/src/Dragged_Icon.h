#pragma once
#include"Vector.h"
#include"eBullet.h"
#include"IDropListener.h"
#include"IEraseIcon.h"
#include"IBackListener.h"
#include"IPackagedIcon.h"
#include<array>

namespace Shooting_HackAndSlash::Gun_Custamize {
	class Base_Icon {
	public:
		Base_Icon() = default;
		virtual ~Base_Icon() = default;

		virtual void update() = 0;
		virtual void draw() const = 0;
	};

	// マウスカーソルにくっついてくるアイコン
	class Dragged_Icon : public Base_Icon, public IPackagedIcon {
		Vec2 pos;
		// 戻るために使用する添え字
		size_t return_index;
	public:
		eBullet bullet;

		IDropListener& dropper_magazine;
		IDropListener& dropper_backpack;

		IEraseIcon& eraser;
		IBackListener& back_listener;

		void update() override;
		void draw() const override;

		eBullet& get_Bullet() override;
		size_t get_index() override;

		Dragged_Icon(
			const eBullet& bullet,
			size_t index,
			IEraseIcon& eraser,
			IBackListener& home,
			IDropListener& magazine,
			IDropListener& backpack);
		~Dragged_Icon() = default;
	};

	// Dragged_IconのNull代替クラス
	class Dragged_Icon_Null : public Base_Icon {
	public:
		Dragged_Icon_Null() = default;
		~Dragged_Icon_Null() = default;

		void update() override {}
		void draw() const override {}
	};
}
