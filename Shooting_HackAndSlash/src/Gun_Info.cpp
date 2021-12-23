#include "Gun_Info.h"

namespace Shooting_HackAndSlash {
	using namespace Gun_Custamize;

	Gun_Info::Gun_Info() :
		guns()
	{

	}

	void Gun_Info::initialize() {
		Gun_Info::getInstance().guns.resize(0U);
	}

	Gun& Gun_Info::at(size_t i) {
		return Gun_Info::getInstance().guns.at(i);
	}

	void Gun_Info::Add(size_t l) {
		Gun_Info::getInstance().guns.push_back(Gun(l));
	}
}