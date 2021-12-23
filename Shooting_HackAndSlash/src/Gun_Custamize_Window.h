#pragma once
#include"Photo_SharedHandle.h"
#include"Vector.h"
#include"ISetIcon.h"
#include"IEraseIcon.h"

#include"BackPack.h"
#include"Magazine.h"
#include"Dragged_Icon.h"
#include<memory>

namespace Shooting_HackAndSlash {
	// 銃カスタマイズ画面
	class Gun_Custamize_Window : public ISetIcon, public IEraseIcon{
		// インベントリ
		Gun_Custamize::BackPack backpack;

		// 弾を入れる場所
		Gun_Custamize::Magazine magazine;

		// 今ドラッグしている弾を表示する奴
		// *出したり消したりしたいので、スマートポインタで保持する
		std::unique_ptr<Gun_Custamize::Base_Icon> icon;
	public:
		void update();
		void draw() const;

		void SetIcon(const eBullet& bullet_kind, IBackListener& back, size_t index) override;
		void EraseIcon() override;

		Gun_Custamize_Window();
		~Gun_Custamize_Window() = default;
	};
}
