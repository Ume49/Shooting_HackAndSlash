#pragma once
#include"Photo_SharedHandle.h"
#include<array>
#include"BackPack_Slot.h"
#include"eBullet.h"
#include<unordered_map>
#include"ISetIcon.h"
#include"Define_Inventory.h"

namespace Shooting_HackAndSlash::Gun_Custamize {
	// �C���x���g���̓��e��\������N���X
	//
	class BackPack {
		std::vector<BackPack_Slot> slots;

		Photo_SharedHandle null_slot_photo;
		
		Point pos;
		Photo_SharedHandle back_photo;
		ISetIcon& iseticon;
	public:

		void update();
		void draw() const;

		BackPack(const Point& leftup, ISetIcon& i);
		~BackPack() = default;
	};
}
