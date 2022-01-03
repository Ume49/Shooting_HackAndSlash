#pragma once
#include"IDisplayer.h"
#include"Photo_SharedHandle.h"

namespace Shooting_HackAndSlash {
	// 見た目を静止画像で表現するDisplayer
	class PhotoDisplayer : public IDisplayer{
	private:
		Photo_SharedHandle gr_handle;
		// 画像の大きさの半分、座標の補正に使う
		Vec2 gr_half_size;
	public:
		// 描画
		// pos_center: 中央座標
		// direction: 向き
		void display(const Vec2& pos_center, const Vec2& direction) const override;

		PhotoDisplayer(const std::string& path);
		~PhotoDisplayer() = default;
	};
}
