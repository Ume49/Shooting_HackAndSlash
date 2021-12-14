#include "TextDisplayer.h"

#include<DxLib.h>

namespace Shooting_HackAndSlash {
	void TextDisplayer::init() {
		int fontsize = GetFontSize();
		int width = GetDrawStringWidth(me.c_str(), static_cast<int>(me.size()));
		half_size = Vec2(static_cast<float>(width / 2), static_cast<float>(fontsize / 2));
	}

	void TextDisplayer::display(const Vec2& p, const Vec2& direction) const {
		Vec2 pos = p - half_size;
		DrawStringF(pos.x, pos.y, me.c_str(), color);
	}
}