#pragma once
#include<vector>
#include"eBullet.h"

namespace Shooting_HackAndSlash::Gun_Custamize {
	// �e�̏��
	// ���̒e���������U����Ă��邩�A�Ƃ�
	class Gun{
	public:
		std::vector<eBullet> magazine;

		Gun();
		Gun(size_t length);
		~Gun() = default;
	};
}
