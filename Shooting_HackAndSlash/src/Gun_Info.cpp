#include "Gun_Info.h"

namespace {
	// インデックスの初期値
	constexpr int init_index = 0;
}

namespace Shooting_HackAndSlash {
	using namespace Gun_Custamize;

	Gun_Info::Gun_Info() :
		guns(1),
		now_select(::init_index)
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

	Gun& Gun_Info::Now_Gun() {
		auto& ref = Gun_Info::getInstance();

		return ref.guns.at(ref.now_select);
	}

	Gun& Gun_Info::Plus() {
		auto& ref = Gun_Info::getInstance();

		(++ref.now_select) %= ref.guns.size();

		return ref.guns.at(ref.now_select);
	}

	Gun& Gun_Info::Minus() {
		auto& ref = Gun_Info::getInstance();

		auto i = ref.guns.size();

		((--ref.now_select) += i) &= i;

		return ref.guns.at(ref.now_select);
	}
}