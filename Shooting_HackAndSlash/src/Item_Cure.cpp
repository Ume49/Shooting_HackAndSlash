#include "Item_Cure.h"
#include"Define.h"
#include<DxLib.h>
#include"Player.h"
#include"PlayerInfo.h"
#include"Time.h"

namespace {
	constexpr float survival_time = 5.f;
	constexpr float collider_radius = 10.f;
	// 回復量
	const int cure_point = 10;
}

namespace PATH = Shooting_HackAndSlash::Define::Path::Photo;

namespace Shooting_HackAndSlash::Item {
	Cure::Cure(const Vec2& p, Player& pl) :
		AbstructItem(PATH::Cristal),
		survival_time(::survival_time),
		ref_player(pl)
	{
		pos = p;
		collider = CircleCollider(pos, ::collider_radius);
	}

	void Cure::update() {
		// プレイヤーとの衝突判定
		if (collider.isColide(ref_player.collider)) {
			// プレイヤーを回復して、このアイテムは消滅
			PlayerInfo::Cure(cure_point);

			is_dead = true;
		}

		// 生存時間が終了したら消滅
		if ((survival_time -= Time::DeltaTime()) <= 0.f) {
			is_dead = true;
		}
	}

	void Cure::draw() const {
		// 見た目を描画
		display();
	}
}