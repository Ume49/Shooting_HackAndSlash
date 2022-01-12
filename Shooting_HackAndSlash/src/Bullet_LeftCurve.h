#pragma once

#include"AbstructBullet.h"

#include"Survival_Counter.h"

namespace Shooting_HackAndSlash::Bullet {
	class LeftCurve : public AbstructBullet{
		Survival_Counter survival;

		void _update() override;
		void OnCollide(AbstructEnemy& e) override;
		void OnDestroy() override;

	public:
		LeftCurve(_Bullet_Args_Template);
		~LeftCurve() = default;
	};
}
