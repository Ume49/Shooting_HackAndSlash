#pragma once
#include"Vector.h"
#include"eBullet.h"

namespace Shooting_HackAndSlash {
	// �e�N���X�𐶐�����ۂ́A�������܂Ƃ߂��p�b�P�[�W
	struct Bullet_Paramater{
		int resource;
		int damage;
		Vec2 pos;
		eBullet bullet;
		Vec2 direction;
	};
}
