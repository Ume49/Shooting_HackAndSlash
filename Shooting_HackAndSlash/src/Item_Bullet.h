#pragma once

#include"AbstructItem.h"

#include"eBullet.h"

#include"Survival_Counter.h"

namespace Shooting_HackAndSlash::Item {
	class Bullet : public AbstructItem {
		Survival_Counter survival;
		eBullet bullet;

		void OnCollide(Player& p) override;
	public:
		Bullet(const eBullet& bullet, const Vec2& pos, Player& p);
		~Bullet() = default;

		void draw() const override;
	};
}
