#pragma once

#include"SE_SharedHandle.h"

namespace Shooting_HackAndSlash {
	// ���ʉ��v���C���[
	// ����ɂ͈�̃t�@�C�������o�^�ł��Ȃ��̂ŁA�Đ������������t�@�C���̐��������̃C���X�^���X���쐬����K�v������
	class SE_Player{
		SE_SharedHandle handle;
	public:
		SE_Player(const std::string& file_path);
		~SE_Player();

		// �o�^���ꂽ���ʉ����Đ�����
		// ������Ăяo��������ʉ��t�@�C���̍Ō�܂ōĐ������
		void play() const;
	};
}
