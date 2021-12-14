#include"AbstructItem.h"
#include<DxLib.h>

namespace Shooting_HackAndSlash {
	AbstructItem::AbstructItem(const std::string& path) :
		AbstructGameObject(),
		photo_handle(path),
		half_size(),
		is_dead(false) {
		Point temp_size = photo_handle.size();
		half_size = Vec2{ static_cast<float>(temp_size.x),static_cast<float>(temp_size.y) } / 2;
	}

	void AbstructItem::display() const {
		DrawGraphF(pos.x - half_size.x, pos.y - half_size.y, photo_handle, TRUE);
#ifdef _DEBUG
		collider.draw();
#endif // _DEBUG
	}
}