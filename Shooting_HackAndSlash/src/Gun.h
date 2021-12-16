#pragma once
#include<vector>
#include"eBullet.h"

namespace Shooting_HackAndSlash::Gun_Custamize {
	// e‚Ìî•ñ
	// ‰½‚Ì’e‚ª‚¢‚­‚Â‘•“U‚³‚ê‚Ä‚¢‚é‚©A‚Æ‚©
	class Gun{
		std::vector<eBullet> magazine;

	public:
		Gun();
		~Gun() = default;
	};
}
