#include "Bullet_Lancher.h"

#include"Input.h"
#include"Time.h"
#include"PlayerInfo.h"
#include"Gun_Info.h"

namespace {
	constexpr float init_count=0.2f;
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
		// •ûŒüŒvŽZ
		Vec2 direction = (Input::GetMousePosf() - pos).nomalize();

		// ƒpƒ‰ƒ[ƒ^‚Ìì¬‚ÆÝ’è
		Bullet_Paramater para;

		para.pos = pos;
		para.direction = direction;
		para.damage = PlayerInfo::getInstance().atk;
		para.resource = Gun_Info::get_resource();
		//para.bullet

		// ’e¶¬
		controller.Make(para);
	}

	float Bullet_Lancher::show_cooltime() const { return cool_time_count; }
	float Bullet_Lancher::show_max_cooltime() const { return cool_time; }
}