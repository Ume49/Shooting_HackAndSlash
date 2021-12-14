#include "Bomb_count_displayer.h"

#include<DxLib.h>
#include"PlayerInfo.h"

namespace Shooting_HackAndSlash::UI {
	void Bomb_count_displayer::draw() const {
		DrawFormatString(pos.x, pos.y, COLOR, "Bomb: %d", PlayerInfo::getInstance().bomb_count);
	}
}