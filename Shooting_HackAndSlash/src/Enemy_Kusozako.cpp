#include "Enemy_Kusozako.h"

#include"Time.h"
#include"TextDisplayer.h"
#include"Player.h"

namespace {
	constexpr float SPEED = 120.f;
	constexpr int atk = 10;
	constexpr int hp = 1;
	constexpr float collider_radius = 10.f;
}

namespace Shooting_HackAndSlash::Enemy {
	void Kusozako::update() {
		// ˆÚ“®•ûŒü‚ðŒvŽZ
		move_direction = (p.pos - pos).nomalize();

		pos += move_direction * speed * Time::DeltaTime();
		collider.OnPositionChanged(pos);
	}

	void Kusozako::draw() const {
		displayer.display(pos, move_direction);

#ifdef _DEBUG
		collider.draw();
#endif // _DEBUG
	}

#include"TextDisplayer.h"

	Kusozako::Kusozako(const Player& p, const Vec2& spawn_pos) :
		p(p),
		speed(SPEED),
		AbstructEnemy("Resource/misile.png") 
	{
		pos = spawn_pos;

		atk = ::atk;
		hp = ::hp;
		collider = CircleCollider(pos, ::collider_radius);
	}
}