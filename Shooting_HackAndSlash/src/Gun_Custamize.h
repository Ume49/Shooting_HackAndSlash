#pragma once
#include"Photo_SharedHandle.h"
#include"Vector.h"

namespace Shooting_HackAndSlash {
	// �e�J�X�^�}�C�Y���
	class Gun_Custamize{

	public:
		void update();
		void draw() const;

		Gun_Custamize();
		~Gun_Custamize() = default;
	};
}
