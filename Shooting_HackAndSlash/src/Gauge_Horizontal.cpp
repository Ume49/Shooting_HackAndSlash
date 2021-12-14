#include "Gauge_Horizontal.h"

#include<DxLib.h>
#include<cassert>

namespace Shooting_HackAndSlash {
	Gauge_Horizontal::Gauge_Horizontal(const std::string& path, const std::string& b, const Point& p) :
		pos(p),
		photo_size(),
		photo(path),
		photo_back(b){
		GetGraphSize(photo, &photo_size.x, &photo_size.y);
	}

	void Gauge_Horizontal::draw(float value) const {
		assert(value >= 0.f && value <= 1.f);

		// �󔒕����̕`��
		DrawGraph(pos.x, pos.y, photo_back, TRUE);

		// �`�悷�钷�����v�Z
		int draw_length = static_cast<int>(static_cast<float>(photo_size.x) * value);

		// �Q�[�W�����̕`��
		DrawRectGraph(pos.x, pos.y, 0, 0, draw_length, photo_size.y, photo, TRUE);
	}

	int Gauge_Horizontal::Height() const {
		return photo_size.y;
	}

	int Gauge_Horizontal::Max_Width() const {
		return photo_size.x;
	}

	const Point& Gauge_Horizontal::size() const {
		return photo_size;
	}
}