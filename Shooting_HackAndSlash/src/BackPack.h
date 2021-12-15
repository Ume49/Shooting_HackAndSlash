#pragma once
#include"Photo_SharedHandle.h"
#include<vector>
#include"BackPack_Slot.h"


namespace Shooting_HackAndSlash {
	// 現在所持している弾丸を表示する場所
	// スクロールできるようにする？
	// とりあえずスクロールなしで作る
	class BackPack {
		std::vector<BackPack_Slot> slots;
		Point pos;
		Photo_SharedHandle back_photo;


	public:

		void update();
		void draw() const;

		BackPack(const Point& leftup);
		~BackPack() = default;
	};
}
