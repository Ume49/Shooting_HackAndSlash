#pragma once

#include<vector>
#include<string>
#include"Button.h"

namespace Shooting_HackAndSlash {
	class ButtonController {
	private:
		std::vector<UI::Button> buttons;
	public:
		void update();
		void draw() const;

		// �{�^���ǉ��֐�
		// onclick	: �N���b�N�������ɌĂ΂�鏈��
		// text	: ���o���Ƃ��ĕ\�����镶��
		// p_leftup	: �{�^���̊�ƂȂ���W�A�������{�^���̍���Ƃ��ĕ\������
		void Add(std::function<void(void)> onclick, const std::string& text, const Point& p_leftup);
		ButtonController() = default;
		~ButtonController() = default;
	};
}
