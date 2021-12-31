#pragma once

#include<list>
#include<memory>
#include"AbstructBullet.h"
#include"Vector.h"
#include"Bullet_Paramater.h"

namespace Shooting_HackAndSlash {
	class EnemyController;
	class BulletController {
	private:
		EnemyController& enemy_con;
		std::list<std::unique_ptr<AbstructBullet>> bullets;
	public:
		void update();
		void draw() const;

		void Make(const Bullet_Paramater& bp);

		BulletController(EnemyController& e) : bullets(), enemy_con(e) {}
		~BulletController() = default;
	};
}