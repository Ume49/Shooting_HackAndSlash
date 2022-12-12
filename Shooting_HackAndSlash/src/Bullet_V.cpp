#include"Bullet_V.h"
#include"BulletController.h"

#include<cmath>
#include<numbers>

#include"Define.h"

namespace {
	// 発射される二つの弾丸が為す角度
	// 後ろの計算式は度数法をラジアン表記に変換するための式
	constexpr float v_angle = 30.f * static_cast<float>(std::numbers::pi) / 180.f;

	constexpr int	launch_count	= 2;		// 発射する個数
	constexpr float damage_decrease = 0.8f;		// ダメージ減衰率
}

namespace Shooting_HackAndSlash::Bullet {
	V::V(const Bullet_Paramater& p, std::unique_ptr<Bullet_Resource>& resource, BulletController& b, EnemyController& e) :
		AbstructBullet(Define::Path::Photo::Bullet, p, resource, e, b) {
		// すぐ消去されるようにする
		this->is_dead		= true;
		this->is_destroy	= true;

		// ダメージ減衰
		this->damage = static_cast<int>(p.damage * ::damage_decrease);
	}

	void V::OnCollide(AbstructEnemy& e) {}	// 何もしない

	void V::_update() {}	// 何もしない

	void V::OnDestroy() {
		Bullet_Paramater para;

		// パラメータの設定
		para.damage = this->damage;
		para.pos	= this->pos;

		// 弾取得
		eBullet bullet = resource->get();

		// 現在の角度を取得
		float now_angle = std::atan2f(velocity.y, velocity.x);

		// 左側の角度を計算
		float left_angle = now_angle - ::v_angle / 2.f;
		// 右側の角度を計算
		// 計算リソースをケチるために左側の角度から求める
		float right_angle = left_angle + ::v_angle;

		// 弾作成関数
		auto make = [&](float angle) {
			// 方向
			Vec2 direction;

			// xとy成分をそれぞれ求める
			direction.x = std::cosf(angle);
			direction.y = std::sinf(angle);

			// 代入
			para.direction = direction;

			// リソースの複製
			std::unique_ptr<Bullet_Resource> r(std::make_unique<Bullet_Resource>(*resource));

			// 作成
			bulletcontroller_ref.Make(bullet, para, r);
		};

		// 二個生成
		make(left_angle);
		make(right_angle);
	}
}