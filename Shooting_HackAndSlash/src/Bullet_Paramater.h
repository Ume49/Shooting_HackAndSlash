#pragma once
#include"Vector.h"
#include"eBullet.h"

namespace Shooting_HackAndSlash {
	class BulletController;
	class EnemyController;

	// �e�N���X�𐶐�����ۂ́A�������܂Ƃ߂��p�b�P�[�W
	class Bullet_Paramater {
	public:
		// �_���[�W
		int damage;
		// �����ʒu
		Vec2 pos;
		// ����
		Vec2 direction;

		Bullet_Paramater();
		~Bullet_Paramater() = default;
	};
}
