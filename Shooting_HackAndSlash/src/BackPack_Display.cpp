#include"BackPack_Display.h"
#include<DxLib.h>
#include"Inventory_Info.h"
#include"Icon_Table.h"
#include"Define.h"

namespace {
	// �X���b�g���m�̊Ԋu
	constexpr int Button_distance = 74;

	// �X���b�g�����ɉ����ׂ邩
	constexpr int x = 2;

	// �X���b�g�̏����ʒu
	constexpr int init_x = 10, init_y = 10;
}

namespace Shooting_HackAndSlash::Gun_Custamize {
	BackPack_Display::BackPack_Display(const Point& p, ISetIcon& i) :
		null_slot_photo(Define::Path::Photo::Slot),
		slots(),
		pos(p),
		iseticon(i)
	{
		// �X���b�g�̏����ʒu�����߂�
		Point init = p + Point{ ::init_x, ::init_y };

		// �X���b�g�̗̈��\��
		slots.reserve(static_cast<size_t>(Inventory_Info::getInstance().owned_item.size()));

		// �X���b�g���c�ɉ����ׂ邩
		int height = Inventory_Length / ::x;

		// �X���b�g��o�^
		for (auto y = 0; y < height; y++) {
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

		// �X���b�g�̐퓬�C�e���[�^���擾
		auto iter = slots.cbegin();

		// �C���x���g�����Q��
		for (auto& w : Inventory_Info::getInstance().owned_item) {
			if (w == eBullet::Null) {	// ���g����̏ꍇ
				iter->draw();
			}
			else {						// ���g������ꍇ
				// ���W���擾
				auto pos = iter->get_center();

				namespace R = Define::RotaGraph_Default;

				// �摜�n���h�����擾
				int handle = Icon_Table::at(w);

				DrawRotaGraph(pos.x, pos.y, R::ExRate, R::Angle, handle, TRUE);
			}

			iter++;
		}
	}
}