#include "Time.h"

namespace Shooting_HackAndSlash{
	const float Time::DeltaTime(){
		return Time::getInstance().deltatime;
	}

	void Time::update() {
		Time& time = Time::getInstance();

		// ���݂̎���
		int nowTime = GetNowCount();

		// int�^�ŕϗʂ��擾
		int delta_int = nowTime - time.pastTime;

		time.deltatime = static_cast<float>(delta_int) / 1000.f;
		// �ߋ��̎������X�V
		time.pastTime = nowTime;
	}

	void Time::SetTimer() {
		Time::getInstance().start_time = GetNowCount();
	}

	void Time::StopTimer() {
		Time& time = Time::getInstance();

		// �X�g�b�v���_�ł̎������擾
		int end_time = GetNowCount();
		// ���b�o�߂����������߂�A���łɃ~���b�̒P�ʂ�؂藎�Ƃ�
		int delta = (end_time - time.start_time) / 1000;

		// �b�ƕ����v�Z
		time.minute = delta / 60;
		time.seconds = delta % 60;
	}

	void Time::ResetTimer() {
		Time::getInstance().start_time = 0;
	}

	int Time::GetTimer_minute() {
		return Time::getInstance().minute;
	}

	int Time::GetTimer_seconds() {
		return Time::getInstance().seconds;
	}
}