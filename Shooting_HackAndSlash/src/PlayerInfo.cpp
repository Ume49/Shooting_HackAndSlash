#include "PlayerInfo.h"
#include<cassert>
#include<algorithm>

namespace Shooting_HackAndSlash
{
	void PlayerInfo::initialize() {
		PlayerInfo& p = PlayerInfo::getInstance();

		p.hp = INIT_HP;
		p.max_hp = INIT_HP;
		p.speed = INIT_SPEED;
		p.bomb_count = INIT_BOMB;
	}

	void PlayerInfo::Cure(int v) {
		assert(v >= 0);
		
		auto& p = PlayerInfo::getInstance();

		p.hp = std::clamp((p.hp + v), 0, p.max_hp);
	}
}