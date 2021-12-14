#include "BulletController_Player.h"

#include<algorithm>
#include"EnemyController.h"
#include"TestBullet.h"

namespace Shooting_HackAndSlash {
	void BulletController_Player::update() {
		// �e�ۂ̍X�V�Ăяo��
		for (auto& w : bullets) {
			w->update();
		}

		// �����蔻��`�F�b�N

		// ���S���Ă���e�ۂ͏���
		bullets.remove_if([](std::unique_ptr<AbstructBullet>& w) {return w->is_dead; });
	}

	void BulletController_Player::draw() const {
		for (auto& w : bullets) {
			w->draw();
		}
	}

	void BulletController_Player::Make(const Vec2& pos, const Vec2& direction, float speed, int damage) {
		bullets.push_back(std::make_unique<Bullet::TestBullet>(pos, direction, speed, damage, enemy_con));
	}
}