#include "Item_Bullet.h"

#include"Player.h"

#include"Icon_Table.h"

#include"Inventory_Info.h"

namespace {
	// •`‰æ‚·‚éŽž‚ÌŠg‘å—¦
	constexpr double Extend_rate = 0.6;

	constexpr float survival_time = 6.f;
}

namespace Shooting_HackAndSlash::Item {
	Bullet::Bullet(const eBullet& b, Player& p, const Vec2& position) :
		AbstructItem(Gun_Custamize::Icon_Table::at(b).getkey(), p, position),
		survival(::survival_time),
		bullet(b)
	{
	}

	void Bullet::OnCollide(Player& p) {
		if (!Inventory_Info::Add(bullet)) {
			is_dead = false;
		}
	}

	void Bullet::draw() const {
		display(::Extend_rate);
	}
}