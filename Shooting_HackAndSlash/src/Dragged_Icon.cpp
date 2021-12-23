#include"Dragged_Icon.h"
#include"Input.h"
#include"Define.h"
#include<DxLib.h>
#include"Icon_Table.h"

namespace Shooting_HackAndSlash::Gun_Custamize {
	Dragged_Icon::Dragged_Icon(const eBullet& b, size_t index, IEraseIcon& e, IBackListener& home, IDropListener& magazine, IDropListener& backpack) :
		return_index(index),
		bullet(b),
		pos(),
		dropper_backpack(backpack),
		dropper_magazine(magazine),
		eraser{ e },
		back_listener{ home }
	{
		pos = Input::GetMousePosf();
	}

	void Dragged_Icon::update() {
		pos = Input::GetMousePosf();

		if (Input::GetUp(Inputcode::Fire1)) {	// マウスから指が離れたとき
			bool flag = false;

			flag |= dropper_backpack.CheckDrop(bullet);
			flag |= dropper_magazine.CheckDrop(bullet);

			// どこにもドロップできなかった場合は元の場所へ返す
			if (not flag) { back_listener.Back(return_index, bullet); }

			eraser.EraseIcon();
		}
	}

	void Dragged_Icon::draw() const {
		using namespace Define::RotaGraph_Default;
		DrawRotaGraphF(pos.x, pos.y, ExRate, Angle, Icon_Table::at(bullet), TRUE);
	}
}