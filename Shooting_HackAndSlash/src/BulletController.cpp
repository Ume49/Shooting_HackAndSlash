#include "BulletController.h"

#include<algorithm>
#include"EnemyController.h"

#include"Bullet_ST.h"

namespace Shooting_HackAndSlash {
	void BulletController::update() {
		// ’eŠÛ‚ÌXVŒÄ‚Ño‚µ
		for (auto& w : bullets) {
			w->update();
		}

		// €–S—\’è‚Ì“z‚©‚çonDestroy‚ğŒÄ‚Ño‚·
		for (auto& w : bullets) { if (w->is_dead) { w->OnDestroy(); } }

		// €–S‚µ‚Ä‚¢‚é’eŠÛ‚ÍÁ‹
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