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

	// ‹ó—“‚ğŒŸõ‚µ‚Ä’Ç‰Á‚·‚é
	bool Inventory_Info::Add(const eBullet& b) {
		auto& container = Inventory_Info::getInstance().owned_item;

		// ‹ó‚ÌêŠ‚ğ’T‚·
		auto itr = std::find(container.begin(), container.end(), eBullet::Null);

		// ‹ó‚¢‚½êŠ‚ª‚È‚¢‚È‚çfalse‚Å•Ô‚·
		if (itr == container.end()) return false;

		// ŒŸõ‚µ‚½êŠ‚É‘ã“ü
		*itr = b;

		return true;
	}
}