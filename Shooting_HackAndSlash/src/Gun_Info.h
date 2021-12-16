#pragma once
#include"Singleton.h"
#include<vector>
#include"Gun.h"

namespace Shooting_HackAndSlash {
	class Gun_Info : public Singleton<Gun_Info> {
		friend Singleton;
		Gun_Info();
		~Gun_Info() = default;

		// Œ»İŠ—L‚µ‚Ä‚¢‚ée
		std::vector<Gun> guns;
	public:
		
	};
}
