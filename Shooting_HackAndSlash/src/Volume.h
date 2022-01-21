#pragma once
#include"Vector.h"
#include"Photo_SharedHandle.h"
#include"Button.h"
#include"Gauge_Horizontal.h"
#include<memory>
#include<functional>

namespace Shooting_HackAndSlash {
	class Volume {
		float value;

		// �h���b�O����Ă��邩
		bool is_dragged;

		std::unique_ptr<UI::Button> touch_pannel;
		Gauge_Horizontal gauge;
		// �[�̓_
		int start_x, end_x;
		// �Q�[�W�̒���
		float width;

		struct Clip {
			Photo_SharedHandle handle;
			Point pos;
			int half_width;
		} clip;

		// clip�𓮂������Ƃ��ɌĂяo����鏈��
		std::function<void(float)> func_slided;
	public:
		void update();
		void draw() const;

		// ������Ԃ�
		int height() const;

		// pos		: ����̍��W
		// func_slided	: �܂݂𓮂����x�ɌĂ΂��֐�
		// value : �����l
		Volume(const Point& pos, std::function<void(float)> func_slided, float value = 1.f);
		~Volume() = default;
	};
}
