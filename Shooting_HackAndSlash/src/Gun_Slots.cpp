#include "Gun_Slots.h"
#include<DxLib.h>

namespace Shooting_HackAndSlash::Gun_Custamize {
	Gun_Slots::Gun_Slots() {

	}

	void Gun_Slots::update() {

	}

	void Gun_Slots::draw() const {
		for (auto& w : slots) {
			w.draw();
		}
	}
}
