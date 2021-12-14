#include "Bomb_Launcher.h"

#include"Input.h"

namespace Shooting_HackAndSlash {
	void Bomb_Launcher::check() {
		if (Input::GetDown(Inputcode::Fire2)) {
			Fire();
		}
	}

	void Bomb_Launcher::Fire() {
	}
}