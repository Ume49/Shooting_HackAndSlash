#pragma once
#include"Vector.h"
#include"Color.h"
#include"Font_SharedHandle.h"
#include<string>

namespace Shooting_HackAndSlash {
	// string�^��`�悷�邽�߂̃Z�b�g
	// ����l��
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
