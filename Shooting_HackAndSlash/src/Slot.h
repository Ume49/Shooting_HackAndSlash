#pragma once
#include"Photo_SharedHandle.h"
#include"Vector.h"

namespace Shooting_HackAndSlash::Gun_Custamize {
	// �A�C�e��������X���b�g
	class Slot {
		Photo_SharedHandle null_slot_photo;
		Vec2 pos, size;
	public:
		void update();
		void draw() const;

		Slot();
		~Slot() = default;
	};
}
