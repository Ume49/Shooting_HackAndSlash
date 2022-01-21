#include "BGM_Player.h"

#include<DxLib.h>

namespace Shooting_HackAndSlash {
	BGM_Player::BGM_Player(const std::string& path) :
		handle(path) {
	}

	BGM_Player::~BGM_Player() {
		StopSoundMem(handle);
	}

	void BGM_Player::play() const {
		PlaySoundMem(handle, DX_PLAYTYPE_LOOP, FALSE);
	}

	void BGM_Player::stop() const {
		StopSoundMem(handle);
	}
}