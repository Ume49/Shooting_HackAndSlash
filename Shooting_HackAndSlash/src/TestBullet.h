#pragma once

#include"AbstructBullet.h"

#include"Vector.h"

#include"IDisplayer.h"
#include<string>
#include<memory>

namespace Shooting_HackAndSlash {
	class EnemyController;
	namespace Bullet {
		class TestBullet :public AbstructBullet {
			float survival_count;

			EnemyController& enemies;
		public:
			void _update() override;

			TestBullet(const Vec2& position, const Vec2& direction, float speed, int damage, EnemyController& e);
			~TestBullet() = default;
		};
	}
}