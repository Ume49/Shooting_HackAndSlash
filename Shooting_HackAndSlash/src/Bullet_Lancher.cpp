#include "Bullet_Lancher.h"

#include"Input.h"
#include"Time.h"
#include"PlayerInfo.h"
#include"Gun_Info.h"

#include<memory>
#include"Bullet_Resource.h"

namespace {
	constexpr float init_count = 0.2f;
	constexpr float COOL_TIME = 0.6f;
}

namespace Shooting_HackAndSlash {
	Bullet_Lancher::Bullet_Lancher(BulletController& c) :
		controller(c),
		cool_time(::COOL_TIME),
		cool_time_count(::init_count) {
	}

	void Bullet_Lancher::check(const Vec2& pos) {
		if (cool_time_count == 0.f) {
			if (Input::Get(Inputcode::Fire1)) {
				cool_time_count = cool_time;
				Fire(pos);
			}
		}
		else {
			if ((cool_time_count -= Time::DeltaTime()) <= 0.f) {
				cool_time_count = 0.f;
			}
		}
	}

	void Bullet_Lancher::Fire(const Vec2& pos) {
		// 方向計算
		Vec2 direction = (Input::GetMousePosf() - pos).nomalize();

		// リソース取得
		std::unique_ptr<Bullet_Resource> resource{ std::make_unique<Bullet_Resource>() };

		// パラメータ作成
		Bullet_Paramater para;

		para.damage = PlayerInfo::getInstance().atk;
		para.pos = pos;
		para.direction = direction;

		// 弾取得
		eBullet bullet = resource->get();

		// 弾生成
		controller.Make(bullet, para, resource);
	}

	float Bullet_Lancher::show_cooltime() const { return cool_time_count; }
	float Bullet_Lancher::show_max_cooltime() const { return cool_time; }
}