#include "System.h"

#include"Define.h"
#include"Looper.h"
#include<DxLib.h>

namespace Shooting_HackAndSlash {
	bool System::initialize() {
		// �O����
		// �����Ɏ��s�������̓Q�[�����I������

		// ��������������
		static constexpr int SUCCESS = 0;

		// �E�C���h�E�T�C�Y���̐ݒ�
		if (SetGraphMode(Define::Window::WITDH, Define::Window::HEIGHT, Define::Window::COLOR_BIT_NUM) != DX_CHANGESCREEN_OK) {
			return false;
		}

		// �E�C���h�E���[�h�ɐݒ�
		if (ChangeWindowMode(Define::Window::IS_WINDOW_MODE) != DX_CHANGESCREEN_OK) { return false; }
		// �E�C���h�E�T�C�Y�����R�ɕύX�ł��邩�ǂ����ݒ�
		if (SetWindowSizeChangeEnableFlag(Define::Window::IS_WINDOWSIZE_FLEXIBLE) != SUCCESS) { return false; }
		// �E�C���h�E�̌��o����ݒ�
		if (SetWindowText(Define::GAME_TITLE) != SUCCESS) { return false; }

		// �w�i�̐F��ݒ�
		if (SetBackgroundColor(0, 0, 0) != SUCCESS) { return false; }

		// DX���C�u���������������A�G���[��f�����璼���ɏI��
		if (DxLib_Init() == -1) { return false; }

		// �_�u���o�b�t�@�����O���邽�߂̗���ʂ�ݒ�
		if (SetDrawScreen(DX_SCREEN_BACK) != SUCCESS) { return false; }

		// �J�[�\�����E�C���h�E�̗̈悩��o�Ȃ��悤�ɂ���
		if (SetValidMousePointerWindowOutClientAreaMoveFlag(FALSE) != SUCCESS) { return false; }

		// �����H��t�����ꍇ��true��Ԃ�
		return true;
	}

	void System::main() {
		// ���[�v�@������ă��C�����[�v
		Looper looper;
		while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {
			if (!looper.loop()) {
				break;
			}
		}
	}

	void System::finalize() {
		// �J�[�\����̈悩��o��悤�ɂ���
		SetValidMousePointerWindowOutClientAreaMoveFlag(TRUE);

		// DX���C�u�����I������
		DxLib_End();
	}
}