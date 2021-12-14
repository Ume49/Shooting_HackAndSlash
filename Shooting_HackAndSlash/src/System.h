#pragma once
#include"DxLib.h"

namespace Shooting_HackAndSlash {
	// 処理を呼び出す元締め
	class System {
	public:
		/// <summary>
		/// ゲームの初期化処理
		/// </summary>
		/// <returns>処理を完遂した時はtrue, 失敗した時はfalse</returns>
		bool initialize();
		// メイン処理
		void main();
		// 終了処理
		void finalize();
	private:
	public:
		System() {}
	};
}
