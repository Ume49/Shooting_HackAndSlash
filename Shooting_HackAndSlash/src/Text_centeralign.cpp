#include "Text_centeralign.h"
#include<DxLib.h>

namespace Shooting_HackAndSlash {
	Text_centeralign::Text_centeralign(const std::string& s, const Font_SharedHandle& font, const Color& text_color) :
		text(s),
		half_size(),
		font_handle(font),
		color(text_color) {
		// ������̒����ƍ�������A�␳�p�̑傫�����v�Z
		int height = font_handle.fontsize();	// ����
		int width = GetDrawStringWidthToHandle(text.c_str(), static_cast<int>(text.size()), font_handle);	// ����

		// �����o�ɑ��
		half_size.y = static_cast<float>(height) / 2.f;
		half_size.x = static_cast<float>(width) / 2.f;
	}

	void Text_centeralign::draw(const Vec2& pos) const {
		// ���W��␳
		Vec2 draw_pos = pos - half_size;

		// �`��
		DrawStringFToHandle(draw_pos.x, draw_pos.y, text.c_str(), color, font_handle);
	}

	void Text_centeralign::draw(const Point& pos) const {
		draw(Vec2(static_cast<float>(pos.x), static_cast<float>(pos.y)));
	}
}