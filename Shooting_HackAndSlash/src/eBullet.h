#pragma once

namespace Shooting_HackAndSlash {
	// 弾の種類
	// ST : 直進する
	// Single , Double , Triple : 消滅した後、何個の弾丸を生成するのか
	enum class eBullet : int {
		Null,
		ST,
		V,
		Star,
		Refrect,
		RightCurve,
		LeftCurve
	};

	// 弾をランダムに取得する
	eBullet Random_Bullet();
}