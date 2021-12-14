#include "Time.h"

namespace Shooting_HackAndSlash{
	const float Time::DeltaTime(){
		return Time::getInstance().deltatime;
	}

	void Time::update() {
		Time& time = Time::getInstance();

		// 現在の時刻
		int nowTime = GetNowCount();

		// int型で変量を取得
		int delta_int = nowTime - time.pastTime;

		time.deltatime = static_cast<float>(delta_int) / 1000.f;
		// 過去の時刻を更新
		time.pastTime = nowTime;
	}

	void Time::SetTimer() {
		Time::getInstance().start_time = GetNowCount();
	}

	void Time::StopTimer() {
		Time& time = Time::getInstance();

		// ストップ時点での時刻を取得
		int end_time = GetNowCount();
		// 何秒経過したかを求める、ついでにミリ秒の単位を切り落とす
		int delta = (end_time - time.start_time) / 1000;

		// 秒と分を計算
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