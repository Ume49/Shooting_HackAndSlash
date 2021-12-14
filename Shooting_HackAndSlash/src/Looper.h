#pragma once

#include"SceneLoader.h"

namespace Shooting_HackAndSlash {
	// メインループ部分を呼び出すクラス
	class Looper {
	private:
		SceneLoader scene;
	public:
		// ゲームのメインループ
		bool loop();

		Looper();
		~Looper() = default;
	};
}