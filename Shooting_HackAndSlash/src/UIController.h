#pragma once

#include"Vector.h"
#include<memory>

#include"Bomb_count_displayer.h"
#include"Bullet_CoolTime_Displayer.h"
#include"Photo_SharedHandle.h"
#include"Abstruct_UI.h"

namespace Shooting_HackAndSlash {
	class Player;

	/**
	 * @brief UIオブジェクトをまとめるクラス
	 * @brief 所持しているUIオブジェクトのupdate、draw関数をまとめて呼び出すことができる
	 *
	 * @see Abstruct_UI Photo_SharedHandle
	 * @see UI::Bomb_count_displayer
	 */
	class UIController {
		using List = std::vector<std::unique_ptr<Abstruct_UI>>;

		static constexpr int UI_WIDTH = 120;
		static constexpr uint32_t COLOR = 0xa9a9a9;

		Point draw_pos;

		List ui_objects;

		UI::Bomb_count_displayer bomb;

		Photo_SharedHandle background;

	public:
		/**
		 * @brief 描画関数
		 */
		void draw() const;

		UIController(Player& p);
	};
}
