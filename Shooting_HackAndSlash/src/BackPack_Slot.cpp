#include "BackPack_Slot.h"

#include"Input.h"
#include"Define.h"

namespace {
	const char* Path = Shooting_HackAndSlash::Define::Path::Photo::Slot;
}

namespace Shooting_HackAndSlash {
	BackPack_Slot::BackPack_Slot(const Point& c) :
		leftup(),
		rightdown(),
		photo(::Path)
	{
		Point size = photo.size();

		leftup = c;
		rightdown = c + size;

		center = (rightdown + leftup) / 2;
	}

	bool BackPack_Slot::is_click() const {
		// 指定した数字の内側にいるか
		auto is_inner = [](int value, int min, int max) {
			return value >= min && value <= max;
		};

		// マウスポインタ座標を取得
		Point m_pos = Input::GetMousePos();

		// 判定の外側にいるのであればその時点でfalseを返す
		if (not is_inner(m_pos.x, leftup.x, rightdown.x)) { return false; }
		if (not is_inner(m_pos.y, leftup.y, rightdown.y)) { return false; }

		// ポインタが判定内にあることは確定しているので、右クリックがされたかどうか返すだけで良い
		return Input::GetDown(Inputcode::Fire1);
	}

	void BackPack_Slot::draw() const {
#ifdef _DEBUG
		// 当たり可視化
		DrawBox(leftup.x, leftup.y, rightdown.x, rightdown.y, Palette::Collider, FALSE);
		DrawLine(leftup.x, leftup.y, rightdown.x, rightdown.y, Palette::Collider);
#endif // _DEBUG

		DrawGraph(leftup.x, leftup.y, photo, TRUE);
	}

	const Point& BackPack_Slot::get_center() const{
		return center;
	}
}