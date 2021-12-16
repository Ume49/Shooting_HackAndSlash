#pragma once
#include<unordered_map>
#include"Singleton.h"
#include"eBullet.h"
#include"Photo_SharedHandle.h"

namespace Shooting_HackAndSlash::Gun_Custamize {
	// �e�̎�ނƃA�C�R���摜�n���h���̑Ή��\
	class Icon_Table : public Singleton<Icon_Table>{
		std::unordered_map<eBullet, Photo_SharedHandle> table;

		friend Singleton;
		Icon_Table();
		~Icon_Table() = default;
	public:
		static const Photo_SharedHandle& at(const eBullet& bullet_kind);
	};
}
