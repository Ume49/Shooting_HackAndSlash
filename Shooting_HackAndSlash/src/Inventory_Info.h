#pragma once
#include"Singleton.h"
#include"eBullet.h"
#include<vector>

namespace Shooting_HackAndSlash::Gun_Custamize {
	// Œ»İŠ—L‚µ‚Ä‚¢‚é’eŠÛ‚ğŠi”[‚µ‚Ä‚¨‚­êŠ
	class Inventory_Info : public Singleton<Inventory_Info>{
		friend Singleton;
		Inventory_Info();
		~Inventory_Info() = default;

		// Œ»İ‚Á‚Ä‚¢‚é’eŠÛ
		std::vector<eBullet> owned_item;
	public:
		void initialize();
		
	};
}
