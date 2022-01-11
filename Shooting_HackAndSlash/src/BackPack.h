#pragma once
#include"Photo_SharedHandle.h"
#include"Slot.h"
#include"eBullet.h"
#include<unordered_map>
#include<array>
#include"Define_Inventory.h"

#include"IDragAndDropListener.h"
#include"ISetIcon.h"

namespace Shooting_HackAndSlash::Gun_Custamize {
	// インベントリの内容を表示するクラス
	class BackPack : public IDragAndDropListener {
		std::vector<Slot> slots;

		Photo_SharedHandle null_slot_photo;

		Point pos;
		Photo_SharedHandle back_photo;

		ISetIcon& setter;
	public:

		void update();
		void draw() const;

		bool CheckDrop(IPackagedIcon& i) override;
		void Back(size_t index, const eBullet& bullet) override;

		BackPack(const Point& leftup, ISetIcon& i);
		~BackPack() = default;
	};
}
