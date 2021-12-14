#pragma once

#include<vector>
#include<string>
#include"Button.h"

namespace Shooting_HackAndSlash {
	class ButtonController {
	private:
		std::vector<UI::Button> buttons;
	public:
		void update();
		void draw() const;

		// ボタン追加関数
		// onclick	: クリックした時に呼ばれる処理
		// text	: 見出しとして表示する文章
		// p_leftup	: ボタンの基準となる座標、ここをボタンの左上として表示する
		void Add(std::function<void(void)> onclick, const std::string& text, const Point& p_leftup);
		ButtonController() = default;
		~ButtonController() = default;
	};
}
