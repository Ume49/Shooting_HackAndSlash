#include"BackPack.h"
#include<DxLib.h>
#include"Inventory_Info.h"
#include"Icon_Table.h"
#include"Define.h"
#include"Input.h"

namespace {
	// �X���b�g���m�̊Ԋu
	constexpr int Button_distance = 10;

	// �X���b�g�����ɉ����ׂ邩
	constexpr int x = 2;

	// �X���b�g�̏����ʒu
	constexpr int init_x = 10, init_y = 10;
}

namespace Shooting_HackAndSlash::Gun_Custamize {
	BackPack::BackPack(const Point& p, ISetIcon& i) :
		null_slot_photo(Define::Path::Photo::Slot),
		slots(),
		pos(p),
		setter(i)
	{
		// �X���b�g�̏����ʒu�����߂�
		Point init = p + Point{ ::init_x, ::init_y };

		// �X���b�g�̗̈��\��
		slots.reserve(static_cast<size_t>(Inventory_Info::getInstance().owned_item.size()));

		// �X���b�g���c�ɉ����ׂ邩
		int height = Inventory_Length / ::x;

		// �X���b�g�̃T�C�Y���擾
		auto size = null_slot_photo.size();

		// �X���b�g��o�^
		for (auto y = 0; y < height; y++) {
			for (auto x = 0; x < ::x; x++) {
				Point temp = pos + Point{ ::init_x, ::init_y } + (Point{ Button_distance, Button_distance } + size) * Point { x, y };

				// �o�^
				slots.push_back(Slot(temp, size));
			}
		}
	}

	void BackPack::update() {
		// �A�C�e���h���b�O�֐�
		auto generate = [&](const eBullet& b, size_t index) {
			setter.SetIcon(b, *this, index);
		};

		if (Input::GetDown(Inputcode::Fire1)) {	// ���N���b�N�������ꂽ��
			for (auto i = 0U; i < slots.size(); i++) {	// �S�Ă̓����蔻����`�F�b�N
				if (slots.at(i).is_on_mouse()) {	// �}�E�X���d�Ȃ��Ă���X���b�g�����邩�ǂ���
					//�C���x���g������A�Ή�����e���擾
					auto bullet = Inventory_Info::getInstance().owned_item.at(i);

					if (bullet != eBullet::Null) {
						generate(bullet, i);
						Inventory_Info::SetNull(i);
					}
					break;
				}
			}
		}
	}

	void BackPack::draw() const {
		// �w�i�`��
		DrawGraph(pos.x, pos.y, back_photo, TRUE);

		// �X���b�g�̐퓬�C�e���[�^���擾
		auto iter = slots.cbegin();

#ifdef _DEBUG
		int count = 0;
#endif // _DEBUG

		// �C���x���g�����Q��
		for (auto& w : Inventory_Info::getInstance().owned_item) {
			// ���W���擾
			auto pos = iter->Center();

			// �`�施��
			auto draw = [&](int h) {DrawRotaGraph(pos.x, pos.y, Define::RotaGraph_Default::ExRate, Define::RotaGraph_Default::Angle, h, TRUE); };

			if (w == eBullet::Null) {	// ���g����̏ꍇ
				iter->draw();
				draw(null_slot_photo);
			}
			else {						// ���g������ꍇ
				// �摜�n���h�����擾
				int handle = Icon_Table::at(w);

				draw(handle);
			}

			// �f�o�b�O�p�ɔԍ��`��
#ifdef _DEBUG
			DrawFormatString(pos.x, pos.y, Palette::White, "%d", count);
			count++;
#endif // _DEBUG

			iter++;
		}
	}

	bool BackPack::CheckDrop(const eBullet& b) {
		bool result = false;

		// �R���e�i�̐擪�C�e���[�^���擾
		auto iter = Inventory_Info::getInstance().owned_item.begin();

		// �}�E�X���d�Ȃ��Ă���X���b�g�����邩�T��
		// ���łɂ���ƍ����悤�ɃC�e���[�^���ړ�
		for (auto& w : slots) {
			if (w.is_on_mouse()) {
				result = true;

				// ���
				*iter = b;

				break;
			}

			iter++;
		}

		return result;
	}

	void BackPack::Back(size_t index, const eBullet& bullet) {
		Inventory_Info::Set(index, bullet);
	}
}