#include"BackPack.h"
#include<DxLib.h>

namespace {
	// �X���b�g���m�̊Ԋu
	constexpr int Button_distance = 10;

	// �X���b�g�̌�
	constexpr int x = 3, y = 3;

	// �X���b�g�̈ʒu *���΍��W
	constexpr int init_x = 10, init_y = 10;
}

namespace Shooting_HackAndSlash {
	BackPack::BackPack(const Point& p) :
		slots(),
		pos(p)
	{
		// �X���b�g�̏����ʒu�����߂�
		Point init = p + Point{ ::init_x, ::init_y };

		// �X���b�g�̗̈��\��
		slots.reserve(static_cast<size_t>(::x * ::y));

		// �X���b�g��o�^
		for (auto x = 0; x < ::x; x++) {
			for (auto y = 0; y < ::y; y++) {
				// ���W���v�Z
				Point temp = init + Point{ Button_distance * x, Button_distance * y };

				// �o�^
				slots.push_back(BackPack_Slot(temp));
			}
		}
	}

	void BackPack::update() {
		// �A�C�e���h���b�O�֐�
		auto generate = []() {};

		for (auto& w : slots) {
			if (w.is_click()) {
				generate();
				break;
			}
		}
	}

	void BackPack::draw() const {
		DrawGraph(pos.x, pos.y, back_photo, TRUE);
		for (auto& w : slots) { w.draw(); }
	}
}