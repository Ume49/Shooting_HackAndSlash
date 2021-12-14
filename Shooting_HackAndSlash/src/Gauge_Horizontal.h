#pragma once
#include"Vector.h"
#include"Photo_SharedHandle.h"

namespace Shooting_HackAndSlash {
	// �������Q�[�W
	class Gauge_Horizontal {
		Point pos, photo_size;
		Photo_SharedHandle photo, photo_back;
	public:

		void draw(float value) const;

		// �Q�[�W�̍������擾
		int Height() const;

		// draw(1.f)���Ăяo�����Ƃ��ɕ`�悳���A�Q�[�W�̒������擾
		int Max_Width() const;

		// �摜�̃T�C�Y��Ԃ�
		const Point& size() const;

		// photo_path :	�Q�[�W�����Ɏg�p����摜�̃p�X
		// back_path :	�Q�[�W�̋󔒕����Ɏg�p����摜�̃p�X
		// p :		����̍��W
		Gauge_Horizontal(const std::string& photo_path, const std::string& back_path, const Point& p);
		~Gauge_Horizontal() = default;
	};
}
