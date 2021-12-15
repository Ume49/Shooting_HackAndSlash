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
	public:
		Photo_SharedHandle back_photo;

		void update();
		void draw() const;

		BackPack();
		~BackPack() = default;
	};
}
