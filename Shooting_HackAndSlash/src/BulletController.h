#pragma once

#include<list>
#include<memory>
#include"AbstructBullet.h"
#include"Vector.h"
#include"Bullet_Paramater.h"
#include"Bullet_Resource.h"

namespace Shooting_HackAndSlash {
	class EnemyController;
	class BulletController {
	private:
		EnemyController& enemycontroller_ref;
		std::list<std::unique_ptr<AbstructBullet>> bullets;
	public:
		void update();
		void draw() const;

		// 弾生成補助関数
		// 弾の種類と生成用パラメータを渡す
		void Make(const eBullet& bullet, const Bullet_Paramater& bp, std::unique_ptr<Bullet_Resource>& resource);

		BulletController(EnemyController& e);
		~BulletController() = default;
	};
}