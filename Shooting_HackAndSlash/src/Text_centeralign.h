#pragma once

#include<string>
#include"Vector.h"
#include"Font_SharedHandle.h"
#include"Color.h"

namespace Shooting_HackAndSlash {
	// テキストを渡した座標を基準として中央揃えで描画する
	struct Text_centeralign{
		const Font_SharedHandle font_handle;
		std::string text;
		Vec2 half_size;
		Color color;
	public:
		void draw(const Vec2& center_pos) const;
		void draw(const Point& pos) const;

		Text_centeralign(const std::string& text, const Font_SharedHandle& font, const Color& text_color);
		~Text_centeralign() = default;
	};
}
