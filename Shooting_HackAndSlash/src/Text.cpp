#include"Text.h"
#include<DxLib.h>

namespace Shooting_HackAndSlash {
	void Text::draw() const {
		DrawStringToHandle(pos.x, pos.y, text.c_str(), font_handle, color);
	}

	Text::Text(const std::string& text, const Point& pos, const Color& color, const Font_SharedHandle& font) :
		pos(),
		text(),
		color(color),
		font_handle(font) {
	}
}