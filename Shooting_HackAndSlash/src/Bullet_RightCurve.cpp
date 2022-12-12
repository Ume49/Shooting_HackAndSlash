#include "Bullet_RightCurve.h"

#include"BulletController.h"
#include"AbstructEnemy.h"

#include"Define.h"
#include"Vec2_Rotate.h"

#include"Time.h"

namespace {
	constexpr float survival_count	= 10.f;
	
	constexpr float curve_rength	= 3000.f;	// 右に曲げる力の大きさ

	constexpr float speed			= 1280.f;

	constexpr float collider_radius = 10.f;
}

namespace Shooting_HackAndSlash::Bullet {
	RightCurve::RightCurve(_Bullet_Args_Template) :
		AbstructBullet(Define::Path::Photo::Bullet, p, resource, e, b),
		survival(::survival_count) {
		// 速度を決定
		velocity = p.direction * ::speed;

		// 当たり判定を決定
		collider = CircleCollider(pos, ::collider_radius);
	}

	void RightCurve::_update() {
		// 進行方向に対して右側のベクトルを作る
		auto force = Vec2_Rotate(velocity, Degree_to_Radian(90.f)).nomalize() * ::curve_rength * Time::DeltaTime();

		// 適用する
		velocity += force;

		if (survival.is_end()) {
			is_dead = true;
		}
	}

	void RightCurve::OnCollide(AbstructEnemy& e) {
		is_dead		= true;
		is_destroy	= true;

		e.Damage(damage);
	}

	void RightCurve::OnDestroy() {
		//次の弾を出す

		// 生成する弾を取得
		eBullet bullet = resource->get();

		// 生成パラメータを作成
		Bullet_Paramater para;

		// パラメータ設定
		para.direction	= this->velocity.nomalize();
		para.damage		= this->damage;
		para.pos		= this->pos;

		// 生成
		this->bulletcontroller_ref.Make(bullet, para, resource);
	}
}