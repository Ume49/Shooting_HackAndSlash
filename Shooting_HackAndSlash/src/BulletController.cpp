#include "BulletController.h"

#include<algorithm>
#include"EnemyController.h"

#include"Bullet_ST.h"

namespace Shooting_HackAndSlash {
	void BulletController::update() {
		// �e�ۂ̍X�V�Ăяo��
		for (auto& w : bullets) {
			w->update();
		}

		// ���S�\��̓z����onDestroy���Ăяo��
		for (auto& w : bullets) { if (w->is_dead) { w->OnDestroy(); } }

		// ���S���Ă���e�ۂ͏���
		bullets.remove_if([](std::unique_ptr<AbstructBullet>& w) { return w->is_dead; });
	}

	void BulletController::draw() const {
		for (auto& w : bullets) {
			w->draw();
		}
	}

	void BulletController::Make(const Bullet_Paramater& p) {
		bullets.push_back(std::make_unique<Bullet::ST>(p, *this, enemy_con));
	}
}