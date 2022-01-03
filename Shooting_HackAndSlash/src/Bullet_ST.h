#pragma once
#include"AbstructBullet.h"

namespace Shooting_HackAndSlash {
	namespace Bullet {
		// ’¼i‚·‚é
		class ST : public AbstructBullet {
		private:
			// ¶‘¶ŠÔ
			float survival_count;

		protected:
			// ƒƒCƒ“ˆ—
			void _update() override;

			// “–‚½‚Á‚½‚Ìˆ—
			void OnCollide(AbstructEnemy& enemy) override;
		public:
			// €‚Ê‚Æ‚«‚Ìˆ—
			void OnDestroy() override;

			ST(const Bullet_Paramater& p, std::unique_ptr<Bullet_Resource>& resource, BulletController& b, EnemyController& e);
			~ST() = default;
		};
	}
}
