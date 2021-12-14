#pragma once

namespace Shooting_HackAndSlash{
	// スポーン関数を呼び出すためのインターフェース
	class ISpawnCallListener {
	public:
		// 呼び出し
		virtual void call_spawn() = 0;

		ISpawnCallListener() = default;
		virtual ~ISpawnCallListener() = default;
	};
}
