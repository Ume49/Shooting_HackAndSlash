#pragma once
#include"Singleton.h"
#include"eBullet.h"
#include<array>
#include<vector>
#include"Define_Inventory.h"

namespace Shooting_HackAndSlash {
	// 現在所有している弾丸を格納しておく場所
	class Inventory_Info : public Singleton<Inventory_Info> {
		friend Singleton;
		Inventory_Info();
		~Inventory_Info() = default;
	public:
		static void initialize();

		// コンテナの空いている箇所をイテレータで返す、空いていないならend()を返す
		static std::array<eBullet, Inventory_Length>::iterator container_space();

		// 空欄にする
		static void SetNull(size_t index);

		static void Set(size_t index, const eBullet& Bullet);

		// 空いた場所に追加する
		// 返り値: 空いている場所があったらtrue、ないならfalse
		static bool Add(const eBullet& bullet);

		// 現在持っている弾丸
		std::array<eBullet, Inventory_Length> owned_item;
	};
}
