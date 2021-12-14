#pragma once
#include"Slot.h"
#include<vector>

namespace Shooting_HackAndSlash {
	// 弾を入れるとこ
	class Gun_Slots {
		std::vector<Slot> slots;
	public:
		void update();
		void draw() const;

		Gun_Slots();
		~Gun_Slots() = default;
	};
}
