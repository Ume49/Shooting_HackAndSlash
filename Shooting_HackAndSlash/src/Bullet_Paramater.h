#pragma once
#include"Vector.h"
#include"eBullet.h"

namespace Shooting_HackAndSlash {
	class BulletController;
	class EnemyController;

	// 弾クラスを生成する際の、引数をまとめたパッケージ
	class Bullet_Paramater {
	public:
		// ダメージ
		int damage;
		// 生成位置
		Vec2 pos;
		// 方向
		Vec2 direction;

		Bullet_Paramater();
		~Bullet_Paramater() = default;
	};
}
