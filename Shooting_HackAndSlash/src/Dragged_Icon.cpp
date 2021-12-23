#include"Dragged_Icon.h"
#include"Input.h"
#include"Define.h"
#include<DxLib.h>
#include"Icon_Table.h"

namespace Shooting_HackAndSlash::Gun_Custamize {
	Dragged_Icon::Dragged_Icon(const eBullet& b, IEraseIcon& e, IBackListener& home, IDropListener& magazine, IDropListener& backpack) :
		bullet(b),
		pos(),
		drop_listener{ magazine, backpack },
		eraser{ e },
		back_listener{ home }

	{
		pos = Input::GetMousePosf();
	}

	void Dragged_Icon::update() {
		pos = Input::GetMousePosf();

		if (Input::GetUp(Inputcode::Fire1)) {	// マウスから指が離れたとき
			bool flag = false;

			for (auto& w : drop_listener) {
				// ドロップできるかチェック
				flag |= w.CheckDrop();
			}

			// どこにもドロップできなかった場合は元の場所へ返す
			if (not flag) { back_listener.Back(); }

			eraser.EraseIcon();
		}
	}

	void Dragged_Icon::draw() const {
		DrawRotaGraphF(pos.x, pos.y, 1., 0., Icon_Table::at(bullet), TRUE);
	}
}