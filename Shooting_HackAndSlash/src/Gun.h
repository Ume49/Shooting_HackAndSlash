#pragma once
#include<vector>
#include"eBullet.h"

namespace Shooting_HackAndSlash::Gun_Custamize {
	// なんの弾が装填されているか、という情報
	class Gun{
		std::vector<eBullet> magazine;

	public:
		Gun();
		~Gun() = default;
	};
}
