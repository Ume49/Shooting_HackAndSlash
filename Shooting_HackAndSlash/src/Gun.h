#pragma once
#include<vector>
#include"eBullet.h"

namespace Shooting_HackAndSlash::Gun_Custamize {
	// �e�̏��
	// ���̒e���������U����Ă��邩�A�Ƃ�
	class Gun{
		std::vector<eBullet> magazine;

	public:
		Gun();
		~Gun() = default;
	};
}
