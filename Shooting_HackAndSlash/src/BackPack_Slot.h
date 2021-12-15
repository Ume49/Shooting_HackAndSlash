#pragma once
#include"Vector.h"
#include"Photo_SharedHandle.h"
#include<memory>

namespace Shooting_HackAndSlash {
	// バックパック向けに当たり判定を提供する
	class BackPack_Slot{
		Point leftup, rightdown, center;
		// 見た目
		Photo_SharedHandle photo;
	public:
		// クリックされたか
		bool is_click() const;
		
		void draw() const;

		const Point& get_center() const;

		BackPack_Slot(const Point& leftup);
		~BackPack_Slot() = default;
	};
}
