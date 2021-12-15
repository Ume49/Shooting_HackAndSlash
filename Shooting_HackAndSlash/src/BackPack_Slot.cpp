#include "BackPack_Slot.h"

#include"Input.h"
#include"Define.h"

namespace {
	const char* Path = Shooting_HackAndSlash::Define::Path::Photo::Slot;
}

namespace Shooting_HackAndSlash {
	BackPack_Slot::BackPack_Slot(const Point& c) :
		leftup(),
		rightdown(),
		photo(::Path)
	{
		Point size = photo.size();

		leftup = c;
		rightdown = c + size;

		center = (rightdown + leftup) / 2;
	}

	bool BackPack_Slot::is_click() const {
		// �w�肵�������̓����ɂ��邩
		auto is_inner = [](int value, int min, int max) {
			return value >= min && value <= max;
		};

		// �}�E�X�|�C���^���W���擾
		Point m_pos = Input::GetMousePos();

		// ����̊O���ɂ���̂ł���΂��̎��_��false��Ԃ�
		if (not is_inner(m_pos.x, leftup.x, rightdown.x)) { return false; }
		if (not is_inner(m_pos.y, leftup.y, rightdown.y)) { return false; }

		// �|�C���^��������ɂ��邱�Ƃ͊m�肵�Ă���̂ŁA�E�N���b�N�����ꂽ���ǂ����Ԃ������ŗǂ�
		return Input::GetDown(Inputcode::Fire1);
	}

	void BackPack_Slot::draw() const {
#ifdef _DEBUG
		// ���������
		DrawBox(leftup.x, leftup.y, rightdown.x, rightdown.y, Palette::Collider, FALSE);
		DrawLine(leftup.x, leftup.y, rightdown.x, rightdown.y, Palette::Collider);
#endif // _DEBUG

		DrawGraph(leftup.x, leftup.y, photo, TRUE);
	}

	const Point& BackPack_Slot::get_center() const{
		return center;
	}
}