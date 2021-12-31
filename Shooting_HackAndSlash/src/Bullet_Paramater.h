#pragma once
#include"Vector.h"
#include"eBullet.h"

namespace Shooting_HackAndSlash {
	// 弾クラスを生成する際の、引数をまとめたパッケージ
	struct Bullet_Paramater{
		int resource;
		int damage;
		Vec2 pos;
		eBullet bullet;
		Vec2 direction;
	};
}
