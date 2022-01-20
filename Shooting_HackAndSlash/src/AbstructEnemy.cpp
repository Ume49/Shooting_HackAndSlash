#include"AbstructEnemy.h"
#include<cassert>

#include"Time.h"

namespace {
	constexpr int init = 0;
	constexpr bool dead_init = false;
}

namespace Shooting_HackAndSlash {
	AbstructEnemy::AbstructEnemy(const std::string& photo_path, Player& p) :
		hp(::init),
		atk(::init),
		collider(),
		is_dead(::dead_init),
		displayer(photo_path),
		player_ref(p),
		direction()
	{
	}

	void AbstructEnemy::Damage(int damage) {
		assert(damage >= 0);

		if ((hp -= damage) <= 0) { is_dead = true; }
	}

	bool AbstructEnemy::is_hp_zero() const {
		return hp <= 0;
	}

	void AbstructEnemy::draw() const {
		displayer.display(pos, direction);

#ifdef _DEBUG		collider.draw();
#endif // _DEBUG
	}
}