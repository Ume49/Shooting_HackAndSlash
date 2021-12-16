#pragma once
#include"Photo_SharedHandle.h"
#include"Vector.h"
#include"ISetIcon.h"
#include"IEraseIcon.h"

#include"BackPack_Display.h"
#include"Magazin_Displayer.h"
#include"Dragged_Icon.h"
#include<memory>

namespace Shooting_HackAndSlash {
	using namespace Gun_Custamize;

	// 銃カスタマイズ画面
	class Gun_Custamize_Window : public ISetIcon, public IEraseIcon{
		// インベントリ
		BackPack_Display backpack;

		// 弾を入れる場所
		Magazin_Displayer magazine;

		// 今ドラッグしている弾を表示する奴
		// *出したり消したりしたいので、スマートポインタで保持する
		std::unique_ptr<Dragged_Icon> icon;

	public:
		void update();
		void draw() const;

		void SetIcon(const eBullet& bullet_kind) override;
		void EraseIcon() override;

		Gun_Custamize_Window();
		~Gun_Custamize_Window() = default;
	};
}
