#pragma once
#include"Photo_SharedHandle.h"

namespace Shooting_HackAndSlash {
	// �A�C�e��������X���b�g
	class Slot {
		Photo_SharedHandle null_slot_photo;

	public:
		void update();
		void draw() const;

		Slot();
		~Slot() = default;
	};
}
