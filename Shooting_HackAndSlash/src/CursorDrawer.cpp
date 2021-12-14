#include "CursorDrawer.h"
#include<DxLib.h>
#include"Input.h"
#include"Define.h"

namespace Shooting_HackAndSlash {
	CursorDrawer::CursorDrawer() :
		photo(Define::Path::Photo::Cursor),
		size() {
		GetGraphSizeF(photo, &size.x, &size.y);

		// �傫���𔼕��ɂ��Ă���
		size.x = size.x / 2.f;
		size.y = size.y / 2.f;

		// ����̃}�E�X�J�[�\�����\����
		SetMouseDispFlag(FALSE);
	}

	CursorDrawer::~CursorDrawer() {
		// ����̃J�[�\����\��
		SetMouseDispFlag(TRUE);
	}

	void CursorDrawer::draw() const {
		// ���S���W��␳
		float draw_x = Input::GetMousePosf().x - size.x;
		float draw_y = Input::GetMousePosf().y - size.y;

		DrawGraphF(draw_x, draw_y, photo, TRUE);
	}
}