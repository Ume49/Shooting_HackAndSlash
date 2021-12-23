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

		if (Input::GetUp(Inputcode::Fire1)) {	// �}�E�X����w�����ꂽ�Ƃ�
			bool flag = false;

			for (auto& w : drop_listener) {
				// �h���b�v�ł��邩�`�F�b�N
				flag |= w.CheckDrop();
			}

			// �ǂ��ɂ��h���b�v�ł��Ȃ������ꍇ�͌��̏ꏊ�֕Ԃ�
			if (not flag) { back_listener.Back(); }

			eraser.EraseIcon();
		}
	}

	void Dragged_Icon::draw() const {
		DrawRotaGraphF(pos.x, pos.y, 1., 0., Icon_Table::at(bullet), TRUE);
	}
}