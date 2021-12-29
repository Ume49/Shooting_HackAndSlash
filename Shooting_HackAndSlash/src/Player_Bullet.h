#pragma once
#include"AbstructBullet.h"
#include"Photo_SharedHandle.h"
#include"Vector.h"

namespace Shooting_HackAndSlash {
	class BulletController_Player;
	class Player_Bullet : public AbstructBullet{
	private:
		// ‰½‰ñ‚Ü‚Å•ªŠò‚Å‚«‚é‚Ì‚©
		int resource;

		BulletController_Player& controller_ref;
	protected:
		// ƒƒCƒ“ˆ—
		void _update() override;

		// “–‚½‚Á‚½‚Ìˆ—
		void OnCollide(AbstructEnemy& enemy) override;
	public:
		Player_Bullet(int resource ,BulletController_Player& b, EnemyController& e);
		~Player_Bullet() = default;
	};
}
