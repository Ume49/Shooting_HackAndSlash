#pragma once
#include<vector>

namespace Shooting_HackAndSlash::Gun_Custamize {
	// �e�̒��g��\������N���X
	// 
	class Magazin_Displayer {
		//std::vector<Slot> slots;
	public:
		void update();
		void draw() const;

		Magazin_Displayer();
		~Magazin_Displayer() = default;
	};
}
