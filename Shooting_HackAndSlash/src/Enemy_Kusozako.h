#pragma once

#include"AbstructEnemy.h"

namespace Shooting_HackAndSlash {
	class Player;
	namespace Enemy {
		class Kusozako : public AbstructEnemy {
		private:
			Vec2 direction;
		public:
			void update() override;

			Kusozako(Player& p, const Vec2& spawn_pos);
			~Kusozako() = default;
		};
	}
}