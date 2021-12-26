#include "Inventory_Info.h"
#include<algorithm>

namespace Shooting_HackAndSlash {
	Inventory_Info::Inventory_Info() :
		owned_item() {
		this->initialize();
	}

	void Inventory_Info::initialize() {
		for (auto& w : Inventory_Info::getInstance().owned_item) {
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
}
