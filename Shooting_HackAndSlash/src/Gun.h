#pragma once
#include<vector>
#include"eBullet.h"

namespace Shooting_HackAndSlash::Gun_Custamize {
	// 銃の情報
	// 何の弾がいくつ装填されているか、とか
	class Gun{
		std::vector<eBullet> magazine;

	public:
		Gun();
		Gun(size_t length);
		~Gun() = default;
	};
}
