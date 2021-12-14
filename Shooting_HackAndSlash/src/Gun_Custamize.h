#pragma once
#include"Photo_SharedHandle.h"
#include"Vector.h"

namespace Shooting_HackAndSlash {
	// 銃カスタマイズ画面
	class Gun_Custamize{

	public:
		void update();
		void draw() const;

		Gun_Custamize();
		~Gun_Custamize() = default;
	};
}
