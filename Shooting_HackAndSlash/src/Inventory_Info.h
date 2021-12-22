#pragma once
#include"Singleton.h"
#include"eBullet.h"
#include<array>
#include<vector>
#include"Define_Inventory.h"

namespace Shooting_HackAndSlash::Gun_Custamize {
	// Œ»İŠ—L‚µ‚Ä‚¢‚é’eŠÛ‚ğŠi”[‚µ‚Ä‚¨‚­êŠ
	class Inventory_Info : public Singleton<Inventory_Info> {
		friend Singleton;
		Inventory_Info();
		~Inventory_Info() = default;
	public:
		void initialize();

		// Œ»İ‚Á‚Ä‚¢‚é’eŠÛ
		std::array<eBullet, Inventory_Length> owned_item;
	};
}
