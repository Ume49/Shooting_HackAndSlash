#pragma once

#include"AbstructBullet.h"

#include"Survival_Counter.h"

namespace Shooting_HackAndSlash::Bullet {
	class Refrect : public AbstructBullet {
	protected:
		void _update() override;
		void OnCollide(AbstructEnemy& e) override;

		Survival_Counter survival;
	public:
		Refrect(_Bullet_Args_Template);
		~Refrect() = default;

		void OnDestroy() override;
	};
}
