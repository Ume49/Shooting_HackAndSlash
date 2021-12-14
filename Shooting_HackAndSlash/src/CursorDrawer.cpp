#include "CursorDrawer.h"
#include<DxLib.h>
#include"Input.h"
#include"Define.h"

namespace Shooting_HackAndSlash {
	CursorDrawer::CursorDrawer() :
		photo(Define::Path::Photo::Cursor),
		size() {
		GetGraphSizeF(photo, &size.x, &size.y);

		// 大きさを半分にしておく
		size.x = size.x / 2.f;
		size.y = size.y / 2.f;

		// 既定のマウスカーソルを非表示に
		SetMouseDispFlag(FALSE);
	}

	CursorDrawer::~CursorDrawer() {
		// 既定のカーソルを表示
		SetMouseDispFlag(TRUE);
	}

	void CursorDrawer::draw() const {
		// 中心座標を補正
		float draw_x = Input::GetMousePosf().x - size.x;
		float draw_y = Input::GetMousePosf().y - size.y;

		DrawGraphF(draw_x, draw_y, photo, TRUE);
	}
}