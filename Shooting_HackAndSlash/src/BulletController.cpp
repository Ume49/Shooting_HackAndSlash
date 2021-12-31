#include "BulletController.h"

#include<algorithm>
#include"EnemyController.h"

#include"Bullet_ST.h"

namespace Shooting_HackAndSlash {
	void BulletController::update() {
		// eΫΜXVΔΡo΅
		for (auto& w : bullets) {
			w->update();
		}

		// S\θΜz©ηonDestroyπΔΡo·
		for (auto& w : bullets) { if (w->is_dead) { w->OnDestroy(); } }

		// S΅Δ’ιeΫΝΑ
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