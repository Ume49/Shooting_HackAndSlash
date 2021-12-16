#include "Slot.h"
#include"Input.h"
#include"Define.h"
#include<DxLib.h>


namespace Shooting_HackAndSlash::Gun_Custamize {
	Slot::Slot() :
		null_slot_photo(),
		pos(),
		size()
	{
	}

	void Slot::update() {
	}

	void Slot::draw() const {
		DrawRotaGraphF(pos.x, pos.y, 1., 0., null_slot_photo, TRUE);
	}
}