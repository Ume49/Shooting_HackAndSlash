#pragma once
#include"Photo_SharedHandle.h"
#include<vector>
#include"Button.h"

namespace Shooting_HackAndSlash {
	// ���ݏ������Ă���e�ۂ�\������ꏊ
	// �X�N���[���ł���悤�ɂ���H
	// �Ƃ肠�����X�N���[���Ȃ��ō��
	class BackPack {
		std::vector<UI::Button> slots;
	public:
		Photo_SharedHandle back_photo;

		void update();
		void draw() const;

		BackPack();
		~BackPack() = default;
	};
}
