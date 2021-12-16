#pragma once
#include"Photo_SharedHandle.h"
#include<vector>
#include"BackPack_Slot.h"
#include"eBullet.h"
#include<unordered_map>

namespace Shooting_HackAndSlash::Gun_Custamize {
	// インベントリの内容を表示するクラス
	//
	class BackPack_Display {
		std::vector<BackPack_Slot> slots;
		Point pos;
		Photo_SharedHandle back_photo;
	public:

		void update();
		void draw() const;

		BackPack_Display(const Point& leftup);
		~BackPack_Display() = default;
	};
}
