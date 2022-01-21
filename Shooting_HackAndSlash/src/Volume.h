#pragma once
#include"Vector.h"
#include"Photo_SharedHandle.h"
#include"Button.h"
#include"Gauge_Horizontal.h"
#include<memory>
#include<functional>

namespace Shooting_HackAndSlash {
	class Volume {
		float value;

		// ドラッグされているか
		bool is_dragged;

		std::unique_ptr<UI::Button> touch_pannel;
		Gauge_Horizontal gauge;
		// 端の点
		int start_x, end_x;
		// ゲージの長さ
		float width;

		struct Clip {
			Photo_SharedHandle handle;
			Point pos;
			int half_width;
		} clip;

		// clipを動かしたときに呼び出される処理
		std::function<void(float)> func_slided;
	public:
		void update();
		void draw() const;

		// 高さを返す
		int height() const;

		// pos		: 左上の座標
		// func_slided	: つまみを動かす度に呼ばれる関数
		// value : 初期値
		Volume(const Point& pos, std::function<void(float)> func_slided, float value = 1.f);
		~Volume() = default;
	};
}
