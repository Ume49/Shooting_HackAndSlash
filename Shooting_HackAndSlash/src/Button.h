#pragma once

#include"AbstructGameObject.h"

#include<functional>
#include<string>

#include"Vector.h"
#include"Text_centeralign.h"
#include"Photo_SharedHandle.h"
#include"SE_Player.h"

namespace Shooting_HackAndSlash {
	namespace UI {
		// AABB方式の当たり判定を利用した、マウスでクリックすることで特定の関数を呼び出すクラス
		// 当たり判定のサイズは画像のサイズに依存
		class Button : public AbstructGameObject {
		private:
			// 当たり判定のための領域
			Point leftup, rightdown;
			// 中央座標
			Vec2 center;
			Text_centeralign text;
			Photo_SharedHandle photo, photo_selected;

			std::function<void(void)> on_click;
			bool isselect;

			SE_Player sound;
		public:
			void update() override;
			void draw() const override;

			// x軸の平行移動
			// 符号をちゃんと意識して渡す
			void Slide_horizontal(int x);

			// 画像を指定しない版、デフォルト画像を使用する
			Button(std::function<void(void)> onclick, const std::string& text, const Point& leftup);
			// 画像を自分で指定する版
			Button(const std::string& photo_path, const std::string& photo_selected_path,  std::function<void(void)> onclick, const std::string& text, const Point& leftup);
			// 当たり判定を自分で指定する版
			// 見た目は用意しない
			Button(const Point& size, std::function<void()> onclick, const Point& leftup);
			~Button() = default;
		};
	}
}