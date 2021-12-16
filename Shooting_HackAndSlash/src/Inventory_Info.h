#pragma once
#include"Singleton.h"
#include"eBullet.h"
#include<vector>

namespace Shooting_HackAndSlash::Gun_Custamize {
	// 現在所有している弾丸を格納しておく場所
	class Inventory_Info : public Singleton<Inventory_Info>{
		friend Singleton;
		Inventory_Info();
		~Inventory_Info() = default;
	public:
		void initialize();

		// 現在持っている弾丸
		std::vector<eBullet> owned_item;
		
	};
}
