#pragma once
#include"Singleton.h"
#include"eBullet.h"
#include<vector>

namespace Shooting_HackAndSlash::Gun_Custamize {
	// ���ݏ��L���Ă���e�ۂ��i�[���Ă����ꏊ
	class Inventory_Info : public Singleton<Inventory_Info>{
		friend Singleton;
		Inventory_Info();
		~Inventory_Info() = default;

		// ���ݎ����Ă���e��
		std::vector<eBullet> owned_item;
	public:
		void initialize();
		
	};
}
