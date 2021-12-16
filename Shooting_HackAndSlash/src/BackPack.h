#pragma once
#include"Photo_SharedHandle.h"
#include<vector>
#include"BackPack_Slot.h"
#include"eBullet.h"
#include<unordered_map>

namespace Shooting_HackAndSlash::Gun_Custamize {
	// ���ݏ������Ă���e�ۂ�\������ꏊ
	// �X�N���[���ł���悤�ɂ���H
	// �Ƃ肠�����X�N���[���Ȃ��ō��
	class BackPack {
		std::vector<BackPack_Slot> slots;
		Point pos;
		Photo_SharedHandle back_photo;
	public:

		void update();
		void draw() const;

		BackPack(const Point& leftup);
		~BackPack() = default;
	};
}
