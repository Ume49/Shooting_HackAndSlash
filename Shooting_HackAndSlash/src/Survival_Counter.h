#pragma once

namespace Shooting_HackAndSlash {
	// 生存時間の終了を管理する
	class Survival_Counter{
		float count;
	public:
		Survival_Counter(float survival_time);
		~Survival_Counter() = default;

		// 生存時間が終了しているのか
		bool is_end();
	};
}
