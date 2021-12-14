#pragma once
#include"Photo_SharedHandle.h"
#include<vector>
#include"Button.h"

namespace Shooting_HackAndSlash {
	// 現在所持している弾丸を表示する場所
	// スクロールできるようにする？
	// とりあえずスクロールなしで作る
	class BackPack {
		std::vector<UI::Button> slots;
	public:
		Photo_SharedHandle back_photo;

		void update();
		void draw() const;

		BackPack();
		~BackPack() = default;
	};
}
