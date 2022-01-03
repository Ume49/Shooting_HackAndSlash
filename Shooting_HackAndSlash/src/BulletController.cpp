#include "BulletController.h"

#include<algorithm>
#include<memory>

#include"EnemyController.h"
#include"Define.h"
#include"eBullet.h"
#include"Bullet_Resource.h"

#include"Bullet_ST.h"
#include"Bullet_V.h"
#include"Bullet_Star.h"

namespace Shooting_HackAndSlash {
	BulletController::BulletController(EnemyController& e) :
		bullets(),
		enemycontroller_ref(e)
	{
	}

	void BulletController::update() {
		// �e�ۂ̍X�V�Ăяo��
		for (auto& w : bullets) {
			w->update();
		}

		// ���S�\��̓z����onDestroy���Ăяo��
		for (auto& w : bullets) { if (w->is_dead && w->is_destroy) { w->OnDestroy(); } }

		// ���S���Ă���e�ۂ͏���
		bullets.remove_if([](std::unique_ptr<AbstructBullet>& w) { return w->is_dead; });
	}

	void BulletController::draw() const {
		for (auto& w : bullets) {
			w->draw();
		}
	}

	void BulletController::Make(
		const eBullet& b,
		const Bullet_Paramater& p,
		std::unique_ptr<Bullet_Resource>& r
	) {
		switch (b) {
		default: break;				// �������Ȃ�
		case eBullet::Null: break;	// �������Ȃ�

		case eBullet::ST:
			bullets.push_back(std::make_unique<Bullet::ST>(p, r, *this, enemycontroller_ref));
			break;
		case eBullet::V:
			bullets.push_back(std::make_unique<Bullet::V>(p, r, *this, enemycontroller_ref));
			break;
		case eBullet::Star:
			bullets.push_back(std::make_unique<Bullet::Star>(p, r, *this, enemycontroller_ref));
			break;
		}
	}
}