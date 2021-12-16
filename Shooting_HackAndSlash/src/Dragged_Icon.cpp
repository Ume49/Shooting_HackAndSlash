#include"Dragged_Icon.h"
#include"Input.h"
#include"Define.h"
#include<DxLib.h>
#include"Icon_Table.h"

namespace Shooting_HackAndSlash::Gun_Custamize {
	Dragged_Icon::Dragged_Icon(const eBullet& b) :
		bullet(b),
		pos()
	{
		pos = Input::GetMousePosf();
	}

	void Dragged_Icon::update() {
		pos = Input::GetMousePosf();
	}

	void Dragged_Icon::draw() const {
		DrawRotaGraphF(pos.x, pos.y, 1., 0., Icon_Table::at(bullet), TRUE);
	}
}