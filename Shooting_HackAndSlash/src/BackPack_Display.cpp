#include"BackPack_Display.h"
#include<DxLib.h>
#include"Inventory_Info.h"
#include"Icon_Table.h"

namespace {
	// �X���b�g���m�̊Ԋu
	constexpr int Button_distance = 74;

	// �X���b�g�̌�
	constexpr int x = 3, y = 3;

	// �X���b�g�̈ʒu *���΍��W
	constexpr int init_x = 10, init_y = 10;
}

namespace Shooting_HackAndSlash::Gun_Custamize {
	BackPack_Display::BackPack_Display(const Point& p, ISetIcon& i) :
		slots(),
		pos(p),
		iseticon(i)
	{
		// �X���b�g�̏����ʒu�����߂�
		Point init = p + Point{ ::init_x, ::init_y };

		// �X���b�g�̗̈��\��
		slots.reserve(static_cast<size_t>(::x * ::y));

		// �X���b�g��o�^
		for (auto y = 0; y < ::y; y++) {
			for (auto x = 0; x < ::x; x++) {
				// ���W���v�Z
				Point temp = init + Point{ Button_distance * x, Button_distance * y };

				// �o�^
				slots.push_back(BackPack_Slot(temp));
			}
		}
	}

	void BackPack_Display::update() {
		// �A�C�e���h���b�O�֐�
		auto generate = [&](const eBullet& b) { 
			iseticon.SetIcon(b);
		};

		for (auto i = 0U; i < slots.size(); i++) {
			if (slots.at(i).is_click()) {
				auto bullet = Inventory_Info::getInstance().owned_item.at(i);

				generate(bullet);
				break;
			}
		}
	}

	void BackPack_Display::draw() const {
		// �w�i�`��
		DrawGraph(pos.x, pos.y, back_photo, TRUE);
		// ��g�`��
		for (auto& w : slots) { w.draw(); }
		// �A�C�e���A�C�R���`��
		auto& inventory = Inventory_Info::getInstance().owned_item;
		for (auto i = 0U; i < inventory.size(); i++) {
			const auto& c = slots.at(i).get_center();

			// �X���b�g�̒�������ɃA�C�R����`��
			DrawRotaGraph(c.x, c.y, 1., 0., Icon_Table::at(inventory.at(i)), TRUE);
		}
	}
}