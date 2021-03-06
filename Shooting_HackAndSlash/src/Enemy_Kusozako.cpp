#include "Enemy_Kusozako.h"

#include"Time.h"
#include"TextDisplayer.h"
#include"Player.h"
#include"PlayerInfo.h"

namespace {
	constexpr float SPEED = 120.f;
	constexpr int atk = 10;
	constexpr int hp = 1;
	constexpr float collider_radius = 10.f;
}

namespace Shooting_HackAndSlash::Enemy {
	Kusozako::Kusozako(Player& p, const Vec2& spawn_pos) :
		AbstructEnemy("Resource/misile.png", p)
	{
		pos = spawn_pos;

		atk = ::atk;
		hp = ::hp;
		collider = CircleCollider(pos, ::collider_radius);
	}

	void Kusozako::update() {
		// 移動方向を計算
		direction = (player_ref.pos - pos).nomalize();

		// 移動
		pos += direction * ::SPEED * Time::DeltaTime();
		collider.OnPositionChanged(pos);

		// プレイヤーと接触していたらダメージを与えて消滅
		if (collider.isColide(player_ref.collider)) {
			is_dead = true;

			PlayerInfo::Damage(this->atk);
		}
	}
}