#pragma once
#include"IDisplayer.h"
#include"Photo_SharedHandle.h"

namespace Shooting_HackAndSlash {
	// �����ڂ�Î~�摜�ŕ\������Displayer
	class PhotoDisplayer : public IDisplayer{
	private:
		Photo_SharedHandle gr_handle;
		// �摜�̑傫���̔����A���W�̕␳�Ɏg��
		Vec2 gr_half_size;
	public:
		// �`��
		// pos_center: �������W
		// direction: ����
		void display(const Vec2& pos_center, const Vec2& direction) const override;

		PhotoDisplayer(const std::string& path);
		~PhotoDisplayer() = default;
	};
}
