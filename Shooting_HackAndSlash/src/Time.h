#pragma once
#include"DxLib.h"
#include"Singleton.h"

namespace Shooting_HackAndSlash {
	class Time : public  Singleton<Time> {
	public:
		/// <summary>
		/// 前回のフレームから今回のフレームまでに経過した時間を返す
		/// </summary>
		/// <returns>ミリ秒</returns>
		static const float DeltaTime();
		/// <summary>
		/// 内部データの更新
		/// </summary>
		static void update();

		// ストップウォッチをセット
		static void SetTimer();
		// ストップウォッチを停止
		static void StopTimer();
		// ストップウォッチをリセット
		static void ResetTimer();
		// ストップウォッチが何分か取得
		static int GetTimer_minute();
		// ストップウォッチが何秒かを取得
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