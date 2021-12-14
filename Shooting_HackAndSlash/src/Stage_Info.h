#pragma once

#include"Singleton.h"
#include<functional>

namespace Shooting_HackAndSlash {
	class Stage_Info : public Singleton<Stage_Info> {
	private:
		// ���݂̃X�e�[�W�ԍ�
		int stage_num;
		// ������
		// ���݃G�l�~�[�����̓|�������A�Ƃ����l
		int enemy_kill_count;
		// �v��������
		// ���̓|�����炻�̃X�e�[�W���N���A�ɂȂ邩�A�Ƃ����l
		int kill_clear_count;
		// �Q�[�����N���A�������ǂ���
		bool clear;

		// �V�[���J�ڊ֐�
		std::function<void(void)> stageclear_func;
	public:
		// �l�̏�����
		static void initialize();

		// �p�����[�^�����̃X�e�[�W�p�ɂ���
		static void Set_Stage_Next();

		// �Q�[�����N���A���Ă��邩
		static bool Is_GameClear();

		// �X�e�[�W���N���A���Ă��邩
		static bool Is_StageClear();

		// �G�l�~�[�����ʒm
		static void Call_Enemy_Kill();

		// �G�l�~�[�����������J
		static int Show_KillCount();

		// �c�蓢���������J
		static int Show_Remaining();

		// �X�e�[�W���N���A���鏈�����Z�b�g
		static void SetStageClearFunc(std::function<void(void)>);

		// �X�e�[�W�ԍ������J
		static int Show_Stage_Num();
	private:
		friend Singleton;
		Stage_Info();
		~Stage_Info() = default;
	};
}
