#pragma once
#include"AbstructBullet.h"
#include"Photo_SharedHandle.h"
#include"Vector.h"
#include"Bullet_Paramater.h"

namespace Shooting_HackAndSlash {
	class BulletController;
	namespace Bullet {
		// ’¼i‚·‚é
		class ST : public AbstructBullet {
		private:
			BulletController& controller_ref;
		protected:
			// ƒƒCƒ“ˆ—
			void _update() override;

			// “–‚½‚Á‚½‚Ìˆ—
			void OnCollide(AbstructEnemy& enemy) override;
		public:
			// €‚Ê‚Æ‚«‚Ìˆ—
			void OnDestroy() override;

			ST(const Bullet_Paramater& p, BulletController& b, EnemyController& e);
			~ST() = default;
		};
	}
}
