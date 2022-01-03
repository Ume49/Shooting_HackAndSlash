#include"Bullet_ST.h"

#include"BulletController.h"
#include"AbstructEnemy.h"

#include"Define.h"
#include"Gun_Info.h"
#include"Time.h"

namespace {
	// 当たり判定の大きさ
	constexpr float collider_radius = 10.f;

	// 移動速度
	constexpr float speed = 1280.f;

	// 速度の減衰度
	constexpr float resistance = 0.99f;

	// 生存時間
	constexpr float survival_count = 0.7f;
}

namespace Shooting_HackAndSlash::Bullet {
	ST::ST(const Bullet_Paramater& p, std::unique_ptr<Bullet_Resource>& resource, BulletController& b, EnemyController& e) :
		AbstructBullet(Define::Path::Photo::Bullet, p, resource, e, b),
		survival_count(::survival_count)
	{
		collider = CircleCollider(this->pos, ::collider_radius);

		this->velocity = p.direction * ::speed;
	}

	void ST::_update() {
		// 減衰させる
		velocity = velocity * ::resistance;

		// 生存時間を更新
		this->survival_count -= Time::DeltaTime();

		if (this->survival_count <= 0.f) {
			is_dead = true;
			is_destroy = false;
		}
	}

	void ST::OnCollide(AbstructEnemy& enemy) {
		is_dead = true;

		enemy.Damage(damage);
	}

	void ST::OnDestroy() {
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