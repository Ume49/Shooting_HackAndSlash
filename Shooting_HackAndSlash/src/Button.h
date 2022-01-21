#pragma once

#include"AbstructGameObject.h"

#include<functional>
#include<string>

#include"Vector.h"
#include"Text_centeralign.h"
#include"Photo_SharedHandle.h"
#include"SE_Player.h"

namespace Shooting_HackAndSlash {
	namespace UI {
		// AABB�����̓����蔻��𗘗p�����A�}�E�X�ŃN���b�N���邱�Ƃœ���̊֐����Ăяo���N���X
		// �����蔻��̃T�C�Y�͉摜�̃T�C�Y�Ɉˑ�
		class Button : public AbstructGameObject {
		private:
			// �����蔻��̂��߂̗̈�
			Point leftup, rightdown;
			// �������W
			Vec2 center;
			Text_centeralign text;
			Photo_SharedHandle photo, photo_selected;

			std::function<void(void)> on_click;
			bool isselect;

			SE_Player sound;
		public:
			void update() override;
			void draw() const override;

			// x���̕��s�ړ�
			// �����������ƈӎ����ēn��
			void Slide_horizontal(int x);

			// �摜���w�肵�Ȃ��ŁA�f�t�H���g�摜���g�p����
			Button(std::function<void(void)> onclick, const std::string& text, const Point& leftup);
			// �摜�������Ŏw�肷���
			Button(const std::string& photo_path, const std::string& photo_selected_path,  std::function<void(void)> onclick, const std::string& text, const Point& leftup);
			// �����蔻��������Ŏw�肷���
			// �����ڂ͗p�ӂ��Ȃ�
			Button(const Point& size, std::function<void()> onclick, const Point& leftup);
			~Button() = default;
		};
	}
}