#pragma once
#include"Singleton.h"
#include"eBullet.h"
#include<array>
#include<vector>
#include"Define_Inventory.h"

namespace Shooting_HackAndSlash::Gun_Custamize {
	// 現在所有している弾丸を格納しておく場所
	class Inventory_Info : public Singleton<Inventory_Info> {
		friend Singleton;
		Inventory_Info();
		~Inventory_Info() = default;
	public:
		void initialize();

		// コンテナの空いている箇所をイテレータで返す、空いていないならend()を返す
		static std::array<eBullet, Inventory_Length>::iterator container_space();

		// 空欄にする
		static void SetNull(size_t index);

		// 現在持っている弾丸
		std::array<eBullet, Inventory_Length> owned_item;
	};
}
