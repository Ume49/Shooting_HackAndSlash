#include"AbstructEnemy.h"
#include<cassert>

namespace {
	constexpr int init = 0;
	constexpr bool dead_init = false;
}

namespace Shooting_HackAndSlash {
	AbstructEnemy::AbstructEnemy(const std::string& photo_path)
		: hp(::init), atk(::init), collider(), is_dead(::dead_init), displayer(photo_path) {
	}

	void AbstructEnemy::Damage(int damage) {
		assert(damage >= 0);

		if ((hp -= damage) <= 0) { is_dead = true; }
	}
}
