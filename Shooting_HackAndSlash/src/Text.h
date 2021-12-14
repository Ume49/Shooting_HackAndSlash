#pragma once
#include"Vector.h"
#include"Color.h"
#include"Font_SharedHandle.h"
#include<string>

namespace Shooting_HackAndSlash {
	// stringŒ^‚ğ•`‰æ‚·‚é‚½‚ß‚ÌƒZƒbƒg
	// ¶ã‹l‚ß
	struct Text{
		std::string text;
		Point pos;
		Color color;
		Font_SharedHandle font_handle;

		void draw() const;
		Text(const std::string& text, const Point& pos, const Color& color, const Font_SharedHandle& font);
		~Text() = default;
	};
}
