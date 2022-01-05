#pragma once

#include"AbstructBullet.h"

namespace Shooting_HackAndSlash::Bullet {
	class Refrect : public AbstructBullet {
	protected:
		void _update() override;
		void OnCollide(AbstructEnemy& e) override;
	public:
		Refrect();
		~Refrect() = default;

		void OnDestroy() override;
	};
}
