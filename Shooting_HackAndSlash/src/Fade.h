#pragma once

namespace Shooting_HackAndSlash {
	class Fade{
		enum class State{
			Wait, Fade, Reset
		} state;

		float bright;
	public:
		// フェード終了時のみ、trueを返す
		bool update();

		// 動作をセット
		void Set();

		Fade();
		~Fade() = default;
	};
}
