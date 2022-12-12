#pragma once
#include"Vector.h"
#include"Photo_SharedHandle.h"
#include"Button.h"
#include"Gauge_Horizontal.h"
#include<memory>
#include<functional>

namespace Shooting_HackAndSlash {
	// UIとしての音量調整に使われる、ボリュームバークラス
	// オーディオミキサーのつまみみたいな機能を提供する
	// 
	// ・どれだけの量があるかを示すゲージクラスと、
	// ・マウスでドラッグしてゲージを操作できるようにするつまみクラス
	// 
	// で構成される
	class Volume {
		// ボリュームがvalue %満たされている、という値。0.f~1.0fの範囲
		float value;

		// ドラッグされているか
		bool is_dragged;

		// つまみ部分を実装するボタンクラス
		// 機能が似ているので既存のものを流用
		std::unique_ptr<UI::Button> touch_pannel;
		
		// どれだけの量があるかを表示するゲージクラス
		Gauge_Horizontal gauge;
		// 端の点
		int start_x, end_x;
		// ゲージの長さ
		float width;

		// つまみを表示するための構造体
		struct Clip {
			Photo_SharedHandle handle;
			Point pos;
			int half_width;
		} clip;

		// clipを動かしたときに呼び出される処理
		std::function<void(float)> func_slided;
	public:
		// 更新処理。毎フレーム1回だけ呼び出す
		// 主にマウスでつまむ処理の実装に必要
		void update();
		
		// 描画処理
		void draw() const;

		// 見た目の高さを返す
		int height() const;

		// pos		: 左上の座標
		// func_slided	: つまみを動かす度に呼ばれる関数
		// value : 初期値
		Volume(const Point& pos, std::function<void(float)> func_slided, float value = 1.f);
		~Volume() = default;
	};
}
