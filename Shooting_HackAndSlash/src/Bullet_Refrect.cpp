#include "Bullet_Refrect.h"

#include"Define.h"

#include"AbstructEnemy.h"
#include"BulletController.h"

namespace {
	using namespace Shooting_HackAndSlash::Define::Window::PlayArea;

	constexpr float x_min = Start::Xf, x_max = End::Xf;
	constexpr float y_min = Start::Yf, y_max = End::Yf;

	constexpr float survival_time = 6.f;

	constexpr float collider_radius = 10.f;

	constexpr float speed = 1280.f;
}

namespace Shooting_HackAndSlash::Bullet {
	Refrect::Refrect(_Bullet_Args_Template) :
		AbstructBullet(Define::Path::Photo::Bullet, p, resource, e, b),
		survival(::survival_time) {
		collider = CircleCollider(pos, ::collider_radius);

		velocity = p.direction * ::speed;
	}

	void Refrect::_update() {
		// 範囲外であるかどうか調べる関数
		auto is_out = [](float value, float max, float min) {
			return value < min || max < value;
		};

		// x方向反転
		if (is_out(pos.x, ::x_max, ::x_min)) {
			velocity.x *= -1.f;
		}
		// y方向反転
		if (is_out(pos.y, ::y_max, ::y_min)) {
			velocity.y *= -1.f;
		}

		// 生存時間が終了したら消滅
		if (survival.is_end()) {
			is_dead = true;
			is_destroy = false;
		}
	}

	void Refrect::OnCollide(AbstructEnemy& e) {
		is_dead = true;
		is_destroy = true;

		e.Damage(damage);
	}

	void Refrect::OnDestroy() {
		//次の弾を出す

		// 生成する弾を取得
		eBullet bullet = resource->get();

		// 生成パラメータを作成
		Bullet_Paramater para;

		// パラメータ設定
		para.direction = this->velocity.nomalize();
		para.damage = this->damage;
		para.pos = this->pos;

		// 生成
		this->bulletcontroller_ref.Make(bullet, para, resource);
	}
}