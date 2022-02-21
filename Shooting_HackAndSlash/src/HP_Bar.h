#pragma once

#include"Abstruct_UI.h"
#include"Gauge.h"
#include"Font_SharedHandle.h"

namespace Shooting_HackAndSlash {
	namespace UI {
		/**
		 * @brief HPから割合を計算してゲージクラスに投げる\nあと装飾もする
		 * @sa Abstruct_UI\nGauge\nPhoto_SharedHandle\nFont_SharedHandle
		 */
		class HP_Bar : public Abstruct_UI {
			/**
			 * @brief 最大HPと現在HPから割合を計算\n上記ステータスは参照をメンバとして所有する
			 * \return 0.f~1.0fの範囲での割合
			 */
			float get_ratio() const;

			int& now_hp, max_hp;
			Gauge gauge;
			Photo_SharedHandle frame_handle, backgr_handle;

			Font_SharedHandle font_handle, mini_font_handle;
		public:
			void draw() const override;

			HP_Bar();
			~HP_Bar() = default;
		};
	}
}
