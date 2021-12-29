#pragma once

#include<list>
#include<memory>
#include"AbstructBullet.h"
#include"Vector.h"

namespace Shooting_HackAndSlash {
	class EnemyController;
	class BulletController_Player {
	private:
		EnemyController& enemy_con;
		std::list<std::unique_ptr<AbstructBullet>> bullets;
	public:
		void update();
		void draw() const;

		void Make(const Vec2& pos, const Vec2& direction, float speed, int damage, int resource);

		BulletController_Player(EnemyController& e) : bullets(), enemy_con(e) {}
		~BulletController_Player() = default;
	};
}