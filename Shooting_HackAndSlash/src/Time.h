#pragma once
#include"DxLib.h"
#include"Singleton.h"

namespace Shooting_HackAndSlash {
	class Time : public  Singleton<Time> {
	public:
		/// <summary>
		/// �O��̃t���[�����獡��̃t���[���܂łɌo�߂������Ԃ�Ԃ�
		/// </summary>
		/// <returns>�~���b</returns>
		static const float DeltaTime();
		/// <summary>
		/// �����f�[�^�̍X�V
		/// </summary>
		static void update();

		// �X�g�b�v�E�H�b�`���Z�b�g
		static void SetTimer();
		// �X�g�b�v�E�H�b�`���~
		static void StopTimer();
		// �X�g�b�v�E�H�b�`�����Z�b�g
		static void ResetTimer();
		// �X�g�b�v�E�H�b�`���������擾
		static int GetTimer_minute();
		// �X�g�b�v�E�H�b�`�����b�����擾
		static int GetTimer_seconds();

	private:
		float deltatime;
		int pastTime;

		int start_time;
		int minute, seconds;

		friend Singleton;
		Time() : deltatime(0.f), pastTime(0), start_time(0), minute(0), seconds(0) {
			pastTime = GetNowCount();
		}
	};
}