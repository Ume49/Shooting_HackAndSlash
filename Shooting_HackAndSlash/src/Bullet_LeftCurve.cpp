#include "Bullet_LeftCurve.h"

#include"BulletController.h"
#include"AbstructEnemy.h"

#include"Define.h"
#include"Vec2_Rotate.h"

#include"Time.h"

namespace {
	constexpr float survival_count	= 3.f;
	
	constexpr float curve_rength	= 3000.f;	// 曲げる力の大きさ

	constexpr float collider_radius = 10.f;

	constexpr float speed			= 1280.f;
}

namespace Shooting_HackAndSlash::Bullet {
	LeftCurve::LeftCurve(_Bullet_Args_Template) :
		AbstructBullet(Define::Path::Photo::Bullet, p, resource, e, b),
		survival(::survival_count) {
		collider = CircleCollider(pos, ::collider_radius);
		
		// 速度を決める
		velocity = p.direction * ::speed;
	}

	void LeftCurve::_update() {
		// 進行方向に対して右側のベクトルを作る
		auto force = Vec2_Rotate(velocity, Degree_to_Radian(-90.f)).nomalize() * ::curve_rength * Time::DeltaTime();

		// 適用する
		velocity += force;

		// 消滅
		if (survival.is_end()) {
			is_dead = true;
		}
	}

	void LeftCurve::OnCollide(AbstructEnemy& e) {
		is_dead		= true;
		is_destroy	= true;

		e.Damage(damage);
	}

	void LeftCurve::OnDestroy() {
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