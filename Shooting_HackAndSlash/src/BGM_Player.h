#pragma once

#include"BGM_SharedHandle.h"

namespace Shooting_HackAndSlash {
	// BGM�v���C���[
	// �폜����鎞�Ɏ����Ŏ~�߂�
	// ���f���Ă���̍Đ��͑O��~�߂��ꏊ����Đ������
	class BGM_Player {
		BGM_SharedHandle handle;
	public:
		BGM_Player(const std::string& file_path);
		~BGM_Player();

		// BGM�Đ�
		void play() const;
		// �Đ����Ă���BGM�𒆎~����
		void stop() const;
	};
}