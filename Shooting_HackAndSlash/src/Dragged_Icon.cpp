#include"Dragged_Icon.h"
#include"Input.h"
#include"Define.h"
#include<DxLib.h>
#include"Icon_Table.h"

namespace Shooting_HackAndSlash::Gun_Custamize {
	Dragged_Icon::Dragged_Icon(const eBullet& b, BackPack& back, Magazine& maga) :
		bullet(b),
		pos(),
		backpack(back),
		magazine(maga)
	{
		pos = Input::GetMousePosf();
	}

	void Dragged_Icon::update() {
		pos = Input::GetMousePosf();

		if (Input::GetUp(Inputcode::Fire1)) {	// マウスから指が離れたとき
		}
	}

	void Dragged_Icon::draw() const {
		DrawRotaGraphF(pos.x, pos.y, 1., 0., Icon_Table::at(bullet), TRUE);
	}
}