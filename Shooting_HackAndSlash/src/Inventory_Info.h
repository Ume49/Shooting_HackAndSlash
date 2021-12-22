#pragma once
#include"Singleton.h"
#include"eBullet.h"
#include<array>
#include<vector>
#include"Define_Inventory.h"

namespace Shooting_HackAndSlash::Gun_Custamize {
	// ���ݏ��L���Ă���e�ۂ��i�[���Ă����ꏊ
	class Inventory_Info : public Singleton<Inventory_Info> {
		friend Singleton;
		Inventory_Info();
		~Inventory_Info() = default;
	public:
		void initialize();

		// ���ݎ����Ă���e��
		std::array<eBullet, Inventory_Length> owned_item;
	};
}
