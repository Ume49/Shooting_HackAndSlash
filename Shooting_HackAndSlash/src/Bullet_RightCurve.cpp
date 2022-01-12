#include "Bullet_RightCurve.h"

#include"Define.h"

#include"Vec2_Rotate.h"

#include"Time.h"

namespace {
	constexpr float survival_count = 10.f;
	// 右に曲げる力の大きさ
	constexpr float curve_rength = 10.f;
}

namespace Shooting_HackAndSlash::Bullet {
	RightCurve::RightCurve(_Bullet_Args_Template) :
		AbstructBullet(Define::Path::Photo::Bullet, p, resource, e, b),
		survival(::survival_count) {
	}

	void RightCurve::_update() {
		// 進行方向に対して右側のベクトルを作る
		auto force = Vec2_Rotate(velocity, Degree_to_Radian(-90.f)).nomalize() * ::curve_rength * Time::DeltaTime();

		// 適用する
		velocity += force;
	}

	void RightCurve::OnCollide(AbstructEnemy& e) {
	}

	void RightCurve::OnDestroy() {
	}
}