#pragma once
#include"Photo_SharedHandle.h"
#include"Vector.h"

#include"BackPack.h"
#include"Gun_Slots.h"

namespace Shooting_HackAndSlash {
	// �e�J�X�^�}�C�Y���
	class Gun_Custamize{
		// ���L���Ă���e�ۂ̃C���x���g��
		BackPack backpack;

		// �J���Ă���e
		Gun_Slots gun;


	public:
		void update();
		void draw() const;

		Gun_Custamize();
		~Gun_Custamize() = default;
	};
}
