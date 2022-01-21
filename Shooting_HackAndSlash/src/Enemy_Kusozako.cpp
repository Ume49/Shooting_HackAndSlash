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
		// �ړ��������v�Z
		direction = (player_ref.pos - pos).nomalize();

		// �ړ�
		pos += direction * ::SPEED * Time::DeltaTime();
		collider.OnPositionChanged(pos);

		// �v���C���[�ƐڐG���Ă�����_���[�W��^���ď���
		if (collider.isColide(player_ref.collider)) {
			is_dead = true;

			PlayerInfo::Damage(this->atk);
		}
	}
}