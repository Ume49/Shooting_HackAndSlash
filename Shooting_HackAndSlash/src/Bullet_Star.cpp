#include "Bullet_Star.h"

#include<cmath>
#include<numbers>

#include"BulletController.h"
#include"Define.h"

namespace {
	// ダメージ減衰率
	constexpr float damage_decrease = 0.6f;

	// 一個の角度
	constexpr float mono_angle = 360.f / 5.f * static_cast<float>(std::numbers::pi) / 180.f;
}

namespace Shooting_HackAndSlash::Bullet {
	Star::Star(const Bullet_Paramater& p, std::unique_ptr<Bullet_Resource>& resource, BulletController& b, EnemyController& e) :
		AbstructBullet(Define::Path::Photo::Bullet, p, resource, e, b)
	{
		// 新生児死亡させる
		this->is_dead = true;
		this->is_destroy = true;

		// ダメージを減らす
		this->damage = static_cast<int>(p.damage * ::damage_decrease);
	}

	void Star::_update() { /* 何もしない */ }
	void Star::OnCollide(AbstructEnemy& e) { /* 何もしない */ }

	void Star::OnDestroy() {
		// 弾取得
		eBullet bullet = resource->get();

		// パラメータ作成
		Bullet_Paramater para;

		para.damage = damage;
		para.pos = pos;

		for (auto i = 0.f; i < 5.f; i++) {
			// 方向計算
			Vec2 dir;

			float temp_angle = ::mono_angle * i;

			dir.x = std::cosf(temp_angle);
			dir.y = std::sinf(temp_angle);

			para.direction = dir;

			// リソース複製
			std::unique_ptr<Bullet_Resource> rsrc{ std::make_unique<Bullet_Resource>(*resource) };

			// 作成
			bulletcontroller_ref.Make(bullet, para, rsrc);
		}
	}
}