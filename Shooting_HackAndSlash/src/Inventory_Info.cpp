#include "Inventory_Info.h"

namespace Shooting_HackAndSlash::Gun_Custamize {
	Inventory_Info::Inventory_Info() :
		owned_item() {
		this->initialize();
	}

	void Inventory_Info::initialize() {
		for (auto& w : owned_item) {
			w = eBullet::Null;
		}
	}
}
