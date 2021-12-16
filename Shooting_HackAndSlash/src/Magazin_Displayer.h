#pragma once
#include<vector>

namespace Shooting_HackAndSlash::Gun_Custamize {
	// 銃の中身を表示するクラス
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
