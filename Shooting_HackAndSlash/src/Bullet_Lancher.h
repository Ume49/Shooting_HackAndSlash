#pragma once

#include"AbstructBullet.h"
#include"BulletController_Player.h"

namespace Shooting_HackAndSlash {
	class Bullet_Lancher {
	private:
		BulletController_Player& controller;

		const float cool_time;
		float cool_time_count;

		void Fire(const Vec2& pos);
	public:
		void check(const Vec2& make_pos);

		float show_cooltime() const;
		float show_max_cooltime() const;

		Bullet_Lancher(BulletController_Player& c);
		~Bullet_Lancher() = default;
	};
}