#include "SE_Player.h"

#include<DxLib.h>

namespace Shooting_HackAndSlash {
	SE_Player::SE_Player(const std::string& path) :
		handle(path) {
	}

	SE_Player::~SE_Player() {
	}

	void SE_Player::play() const {
		PlaySoundMem(handle, DX_PLAYTYPE_BACK);
	}
}