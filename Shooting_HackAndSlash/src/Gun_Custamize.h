#pragma once
#include"Photo_SharedHandle.h"
#include"Vector.h"

#include"BackPack.h"
#include"Gun_Slots.h"

namespace Shooting_HackAndSlash {
	// 銃カスタマイズ画面
	class Gun_Custamize{
		// 所有している弾丸のインベントリ
		BackPack backpack;

		// 開いている銃
		Gun_Slots gun;


	public:
		void update();
		void draw() const;

		Gun_Custamize();
		~Gun_Custamize() = default;
	};
}
