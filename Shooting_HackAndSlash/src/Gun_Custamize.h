#pragma once
#include"Photo_SharedHandle.h"
#include"Vector.h"

#include"BackPack.h"
#include"Gun_Slots.h"

namespace Shooting_HackAndSlash {
	using namespace Gun_Custamize;

	// �e�J�X�^�}�C�Y���
	class Gun_Custamize_Window{
		// ���L���Ă���e�ۂ̃C���x���g��
		BackPack backpack;

		// �J���Ă���e
		Gun_Slots gun;


	public:
		void update();
		void draw() const;

		Gun_Custamize_Window();
		~Gun_Custamize_Window() = default;
	};
}
