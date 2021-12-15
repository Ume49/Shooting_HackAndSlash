#pragma once
#include<vector>
#include"eBullet.h"

namespace Shooting_HackAndSlash {
	// ‚È‚ñ‚Ì’e‚ª‘•“U‚³‚ê‚Ä‚¢‚é‚©A‚Æ‚¢‚¤î•ñ
	class Gun{
		std::vector<eBullet> magazine;

	public:
		Gun();
		~Gun() = default;
	};
}
