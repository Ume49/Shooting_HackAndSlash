#pragma once
#include"AbstructItem.h"

namespace Shooting_HackAndSlash{
	class Player;
	namespace Item {
		class Cure : public AbstructItem {
			float survival_time;
			Player& ref_player;
		public:
			void update() override;
			void draw() const override;

			Cure(const Vec2& pos, Player& p);
			~Cure() = default;
		};
	}
}
