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
	 * @brief UI�I�u�W�F�N�g���܂Ƃ߂�N���X
	 * @brief �������Ă���UI�I�u�W�F�N�g��update�Adraw�֐����܂Ƃ߂ČĂяo�����Ƃ��ł���
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
		 * @brief �`��֐�
		 */
		void draw() const;

		UIController(Player& p);
	};
}
