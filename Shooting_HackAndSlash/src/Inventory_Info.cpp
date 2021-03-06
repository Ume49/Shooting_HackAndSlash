#include "Inventory_Info.h"
#include<algorithm>

namespace Shooting_HackAndSlash {
	Inventory_Info::Inventory_Info() :
		owned_item() {
		for (auto& w : owned_item) {
			w = eBullet::Null;
		}
	}

	void Inventory_Info::initialize() {
		auto& ref_item = Inventory_Info::getInstance().owned_item;

		for (auto& w : ref_item) {
			w = eBullet::Null;
		}
	}

	std::array<eBullet, Inventory_Length>::iterator Inventory_Info::container_space() {
		auto& w = Inventory_Info::getInstance();

		return std::find(w.owned_item.begin(), w.owned_item.end(), eBullet::Null);
	}

	void Inventory_Info::SetNull(size_t index) {
		Inventory_Info::getInstance().owned_item.at(index) = eBullet::Null;
	}

	void Inventory_Info::Set(size_t index, const eBullet& b) {
		Inventory_Info::getInstance().owned_item.at(index) = b;
	}

	// 空欄を検索して追加する
	bool Inventory_Info::Add(const eBullet& b) {
		auto& container = Inventory_Info::getInstance().owned_item;

		// 空の場所を探す
		auto itr = std::find(container.begin(), container.end(), eBullet::Null);

		// 空いた場所がないならfalseで返す
		if (itr == container.end()) return false;

		// 検索した場所に代入
		*itr = b;

		return true;
	}
}