#pragma once
#include"Photo_SharedHandle.h"
#include"Vector.h"
#include"ISetIcon.h"
#include"IEraseIcon.h"

#include"BackPack_Display.h"
#include"Magazin_Displayer.h"
#include"Dragged_Icon.h"
#include<memory>

namespace Shooting_HackAndSlash {
	using namespace Gun_Custamize;

	// �e�J�X�^�}�C�Y���
	class Gun_Custamize_Window : public ISetIcon, public IEraseIcon{
		// �C���x���g��
		BackPack_Display backpack;

		// �e������ꏊ
		Magazin_Displayer magazine;

		// ���h���b�O���Ă���e��\������z
		// *�o������������肵�����̂ŁA�X�}�[�g�|�C���^�ŕێ�����
		std::unique_ptr<Dragged_Icon> icon;

	public:
		void update();
		void draw() const;

		void SetIcon(const eBullet& bullet_kind) override;
		void EraseIcon() override;

		Gun_Custamize_Window();
		~Gun_Custamize_Window() = default;
	};
}
