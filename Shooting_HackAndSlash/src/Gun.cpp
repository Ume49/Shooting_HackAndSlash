#include "Gun.h"

namespace {
	// マガジンの容量の初期値
	constexpr size_t init_magazine_size=2;
}

namespace Shooting_HackAndSlash::Gun_Custamize {
	Gun::Gun() :
		magazine(::init_magazine_size) 
	{
	}

	Gun::Gun(size_t l) :
		magazine(l) 
	{
	}
}