#pragma once
#include"Singleton.h"
#include<vector>
#include"Gun.h"

namespace Shooting_HackAndSlash {
	class Gun_Info : public Singleton<Gun_Info> {
		friend Singleton;
		Gun_Info();
		~Gun_Info() = default;

		// ���ݏ��L���Ă���e
		std::vector<Gun_Custamize::Gun> guns;
	public:
		// ������
		static void initialize();

		// �v�f�ւ̃A�N�Z�X
		static Gun_Custamize::Gun& at(size_t index);

		// �e��ǉ�����
		static void Add(size_t magazine_length);
	};
}
