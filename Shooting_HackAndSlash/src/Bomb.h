#pragma once

#include"AbstructBullet.h"

#include"CircleCollider.h"

namespace Shooting_HackAndSlash {
	namespace Bullet {
		class Bomb : public AbstructBullet {
		private:
		public:
			CircleCollider collider;

			void update() override;
			void draw() const override;

			Bomb() = default;
			~Bomb() = default;
		};
	}
}
