#pragma once
#include"Photo_SharedHandle.h"
#include"Vector.h"
#include"ISetIcon.h"
#include"IEraseIcon.h"

#include"BackPack.h"
#include"Magazine.h"
#include"Dragged_Icon.h"
#include<memory>

namespace Shooting_HackAndSlash {
	// �e�J�X�^�}�C�Y���
	class Gun_Custamize_Window : public ISetIcon, public IEraseIcon{
		// �C���x���g��
		Gun_Custamize::BackPack backpack;

		// �e������ꏊ
		Gun_Custamize::Magazine magazine;

		// ���h���b�O���Ă���e��\������z
		// *�o������������肵�����̂ŁA�X�}�[�g�|�C���^�ŕێ�����
		std::unique_ptr<Gun_Custamize::Base_Icon> icon;
	public:
		void update();
		void draw() const;

		void SetIcon(const eBullet& bullet_kind, IBackListener& back, size_t index) override;
		void EraseIcon() override;

		Gun_Custamize_Window();
		~Gun_Custamize_Window() = default;
	};
}
