#pragma once

#include"Abstruct_UI.h"
#include"Gauge.h"
#include"Font_SharedHandle.h"

namespace Shooting_HackAndSlash {
	namespace UI {
		// HP���犄�����v�Z���ăQ�[�W�N���X�ɓ�����
		// ���Ƒ���������
		class HP_Bar : public Abstruct_UI {
			// �ő�HP�ƌ���HP���犄�����v�Z
			float get_ratio() const;

			int& now_hp, max_hp;
			Gauge gauge;
			Photo_SharedHandle frame_handle,backgr_handle;

			Font_SharedHandle font_handle, mini_font_handle;
		public:
			void draw() const override;

			HP_Bar();
			~HP_Bar() = default;
		};
	}
}