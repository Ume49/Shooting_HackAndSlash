#pragma once
#include"Photo_SharedHandle.h"
#include"BackPack_Slot.h"
#include"eBullet.h"
#include<unordered_map>
#include<array>
#include"Define_Inventory.h"

#include"ISetIcon.h"
#include"IBackListener.h"
#include"IDropListener.h"

namespace Shooting_HackAndSlash::Gun_Custamize {
	// インベントリの内容を表示するクラス
	class BackPack : public IBackListener, public IDropListener {
		std::vector<BackPack_Slot> slots;

		Photo_SharedHandle null_slot_photo;

		Point pos;
		Photo_SharedHandle back_photo;
		ISetIcon& iseticon;
	public:

		void update();
		void draw() const;

		bool CheckDrop() override;
		void Back() override;

		BackPack(const Point& leftup, ISetIcon& i);
		~BackPack() = default;
	};
}
