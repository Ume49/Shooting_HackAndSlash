#pragma once
#include<vector>

namespace Shooting_HackAndSlash::Gun_Custamize {
	// �e�̒��g��\������N���X
	// 
	class Magazine {
		//std::vector<Slot> slots;
	public:
		void update();
		void draw() const;

		Magazine();
		~Magazine() = default;
	};
}
