#pragma once

namespace Shooting_HackAndSlash {
	// Inputクラスから入力を取得する際に利用する、「どの入力を取得するか」を示すEnum
	enum class Inputcode {
		Up, Down, Right, Left,	// 上下左右
		Tab, Esc,				// メニューとかに
		Fire1, Fire2,			// マウスのボタン
		Debug_Exit,				// デバッグ専用。強制終了用ボタン
	};
}