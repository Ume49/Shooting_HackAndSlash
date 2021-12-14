#include "TestBullet.h"

#include"Time.h"
#include"TextDisplayer.h"
#include"EnemyController.h"
#include"Define.h"

namespace {
	constexpr float SURVIVAL_TIME = 0.7f;
}

namespace Shooting_HackAndSlash::Bullet {
	void TestBullet::_update() {
		if ((survival_count -= Time::DeltaTime()) <= 0.f) {
			is_dead = true;
		}

		EnemyController::Enemy_Ref_List list = enemies.Collide(collider);

		// エネミーと一つでも衝突していた場合は消滅
		if (not list.empty()) { is_dead = true; }
		for (auto& w : list) {
			//w->Damage(damage);
			w.get()->Damage(damage);
		}
	}

	TestBullet::TestBullet(const Vec2& position, const Vec2& direction, float speed, int d, EnemyController& e) :
		AbstructBullet(Define::Path::Photo::Bullet),
		survival_count(SURVIVAL_TIME),
		enemies(e)
	{
		pos = position;
		collider = CircleCollider(pos, 7);
		move_direction = direction * speed;
		damage = d;
	}
}