#pragma once
#include<vector>
#include"eBullet.h"

namespace Shooting_HackAndSlash::Gun_Custamize {
	// ‚È‚ñ‚Ì’e‚ª‘•“U‚³‚ê‚Ä‚¢‚é‚©A‚Æ‚¢‚¤î•ñ
	class Gun{
		std::vector<eBullet> magazine;

	public:
		Gun();
		~Gun() = default;
	};
}
