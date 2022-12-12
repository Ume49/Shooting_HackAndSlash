#pragma once

namespace Shooting_HackAndSlash {
	// 弾の種類
	enum class eBullet : int {
		Null,			// 何もない。終端に利用される
		ST,				// 真っすぐ飛ぶ弾
		V,				// 二つに別れてV字に飛ぶ弾
		Star,			// 五つに別れて星型に飛ぶ弾
		Refrect,		// 画面端で反射する弾
		RightCurve,		// 右に曲がっていく弾
		LeftCurve 		// 左に曲がっていく弾		
	};

	// 弾をランダムに取得する
	eBullet Random_Bullet();
}