#pragma once
#include"Vector.h"
#include"Photo_SharedHandle.h"

namespace Shooting_HackAndSlash {
	// 横方向ゲージ
	class Gauge_Horizontal {
		Point pos, photo_size;
		Photo_SharedHandle photo, photo_back;
	public:

		void draw(float value) const;

		// ゲージの高さを取得
		int Height() const;

		// draw(1.f)を呼び出したときに描画される、ゲージの長さを取得
		int Max_Width() const;

		// 画像のサイズを返す
		const Point& size() const;

		// photo_path :	ゲージ部分に使用する画像のパス
		// back_path :	ゲージの空白部分に使用する画像のパス
		// p :		左上の座標
		Gauge_Horizontal(const std::string& photo_path, const std::string& back_path, const Point& p);
		~Gauge_Horizontal() = default;
	};
}
