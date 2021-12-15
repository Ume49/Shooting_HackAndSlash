#include "BackPack_Info.h"
#include"Define.h"

namespace {
	// �\�z�����e�̐�
	constexpr size_t bullet_length = 10;
}

namespace Shooting_HackAndSlash {
	BackPack_Info::BackPack_Info() :
		bullets(),
		icon_table() {
		// ������x�̈���m�ۂ��Ă���
		bullets.reserve(::bullet_length);

		// �e�[�u���o�^
		icon_table.emplace(eBullet::ST_Single, "");
	}

	std::vector<eBullet>& BackPack_Info::getContainer() {
		return BackPack_Info::getInstance().bullets;
	}

	int BackPack_Info::getIcon(const eBullet& i) {
		return BackPack_Info::getInstance().icon_table.at(i);
	}
}