#pragma once
#include"Singleton.h"
#include<vector>
#include"Gun.h"

namespace Shooting_HackAndSlash {
	class Gun_Info : public Singleton<Gun_Info> {
		friend Singleton;
		Gun_Info();
		~Gun_Info() = default;

		// 現在所有している銃
		std::vector<Gun_Custamize::Gun> guns;
	public:
		
	};
}
