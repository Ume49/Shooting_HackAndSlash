#include "Gun.h"

namespace {
	// �}�K�W���̗e�ʂ̏����l
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