#pragma once
#include"AbstructBullet.h"

namespace Shooting_HackAndSlash::Bullet {
	class ST;
	class Star : public AbstructBullet {
		void _update() override;
		void OnCollide(AbstructEnemy& enemy) override;
	public:
		void OnDestroy() override;

		Star(const Bullet_Paramater& p, std::unique_ptr<Bullet_Resource>& resource, BulletController& b, EnemyController& e);
		~Star() = default;
	};
}
