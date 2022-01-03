#pragma once
#include"AbstructBullet.h"

namespace Shooting_HackAndSlash::Bullet {
	class ST;
	class V : public AbstructBullet{
		void _update() override;

		void OnCollide(AbstructEnemy& enemy) override;
	public:
		V(const Bullet_Paramater& p, std::unique_ptr<Bullet_Resource>& resource, BulletController& b, EnemyController& e);
		~V() = default;

		void OnDestroy() override;
	};
}
