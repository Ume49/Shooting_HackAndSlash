#pragma once
#include"AbstructItem.h"

namespace Shooting_HackAndSlash {
	namespace Item {
		class Cure : public AbstructItem {
			void OnCollide(Player& p) override;
		public:
			void draw() const override;

			Cure(const Vec2& pos, Player& p);
			~Cure() = default;
		};
	}
}
