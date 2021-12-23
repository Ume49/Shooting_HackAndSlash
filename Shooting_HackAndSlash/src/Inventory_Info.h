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

		// �R���e�i�̋󂢂Ă���ӏ����C�e���[�^�ŕԂ��A�󂢂Ă��Ȃ��Ȃ�end()��Ԃ�
		static std::array<eBullet, Inventory_Length>::iterator container_space();

		// �󗓂ɂ���
		static void SetNull(size_t index);

		// ���ݎ����Ă���e��
		std::array<eBullet, Inventory_Length> owned_item;
	};
}
