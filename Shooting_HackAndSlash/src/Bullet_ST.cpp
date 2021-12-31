#include"Bullet_ST.h"

#include"BulletController.h"
#include"AbstructEnemy.h"

#include"Define.h"
#include"Gun_Info.h"

namespace {
	// 当たり判定の大きさ
	constexpr float collider_radius = 10.f;

	// 移動速度
	constexpr float speed = 640.f;
}

namespace Shooting_HackAndSlash::Bullet {
	ST::ST(const Bullet_Paramater& p, BulletController& b, EnemyController& e) :
		AbstructBullet(Define::Path::Photo::Bullet, e),
		controller_ref(b)
	{
		damage = p.damage;
		velocity = p.direction * ::speed;
		pos = p.pos;
		resource = p.resource;
		collider = CircleCollider(pos, ::collider_radius);
	}

	void ST::_update() {
	}

	void ST::OnCollide(AbstructEnemy& enemy) {
		is_dead = true;

		enemy.Damage(damage);
	}

	void ST::OnDestroy() {
		//次の弾を出す

		// リソースが無いのであれば終了
		if (resource == 0) return;

		// リソースから生成する弾のインデックスを取得
		// *バグあるかも
		int temp_index = Gun_Info::get_resource() - this->resource;

		// 生成する弾を取得
		eBullet b = Gun_Info::Now_Gun().magazine.at(temp_index);

		// 生成パラメータを作成
		Bullet_Paramater temp_para;

		// パラメータ設定
		temp_para.direction = this->velocity.nomalize();
		temp_para.damage = this->damage;
		temp_para.bullet = b;
		temp_para.pos = this->pos;
		temp_para.resource = this->resource - 1;

		// 生成
		this->controller_ref.Make(temp_para);
	}
}