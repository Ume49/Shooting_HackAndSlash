#include "BackPack_Info.h"
#include"Define.h"

namespace {
	// 予想される弾の数
	constexpr size_t bullet_length = 10;
}

namespace Shooting_HackAndSlash {
	BackPack_Info::BackPack_Info() :
		bullets(),
		icon_table() {
		// ある程度領域を確保しておく
		bullets.reserve(::bullet_length);

		// テーブル登録
		icon_table.emplace(eBullet::ST_Single, "");
	}

	std::vector<eBullet>& BackPack_Info::getContainer() {
		return BackPack_Info::getInstance().bullets;
	}

	int BackPack_Info::getIcon(const eBullet& i) {
		return BackPack_Info::getInstance().icon_table.at(i);
	}
}