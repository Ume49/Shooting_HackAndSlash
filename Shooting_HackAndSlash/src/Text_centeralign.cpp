#include "Text_centeralign.h"
#include<DxLib.h>

namespace Shooting_HackAndSlash {
	Text_centeralign::Text_centeralign(const std::string& s, const Font_SharedHandle& font, const Color& text_color) :
		text(s),
		half_size(),
		font_handle(font),
		color(text_color) {
		// 文字列の長さと高さから、補正用の大きさを計算
		int height = font_handle.fontsize();	// 高さ
		int width = GetDrawStringWidthToHandle(text.c_str(), static_cast<int>(text.size()), font_handle);	// 長さ

		// メンバに代入
		half_size.y = static_cast<float>(height) / 2.f;
		half_size.x = static_cast<float>(width) / 2.f;
	}

	void Text_centeralign::draw(const Vec2& pos) const {
		// 座標を補正
		Vec2 draw_pos = pos - half_size;

		// 描画
		DrawStringFToHandle(draw_pos.x, draw_pos.y, text.c_str(), color, font_handle);
	}

	void Text_centeralign::draw(const Point& pos) const {
		draw(Vec2(static_cast<float>(pos.x), static_cast<float>(pos.y)));
	}
}