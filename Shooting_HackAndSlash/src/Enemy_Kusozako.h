#pragma once

#include"AbstructEnemy.h"

namespace Shooting_HackAndSlash {
	class Player;
	namespace Enemy {
		class Kusozako : public AbstructEnemy {
		private:
			const Player& p;
			Vec2 move_direction;
			float speed;
		public:
			void update() override;
			void draw() const override;

			Kusozako(const Player& p, const Vec2& spawn_pos);
			~Kusozako() = default;
		};
	}
}