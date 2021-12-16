#include "Inventory_Info.h"

namespace Shooting_HackAndSlash::Gun_Custamize {
	Inventory_Info::Inventory_Info() :
		owned_item() {

	}

	void Inventory_Info::initialize() {
		owned_item.clear();
	}
}
