#pragma once
#include<vector>

namespace Shooting_HackAndSlash::Gun_Custamize {
	// 銃の中身を表示するクラス
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
