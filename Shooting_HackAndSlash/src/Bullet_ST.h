#pragma once
#include"AbstructBullet.h"

namespace Shooting_HackAndSlash {
	namespace Bullet {
		// 直進する
		class ST : public AbstructBullet {
		private:
			// 生存時間
			float survival_count;

		protected:
			// メイン処理
			void _update() override;

			// 当たった時の処理
			void OnCollide(AbstructEnemy& enemy) override;
		public:
			// 死ぬときの処理
			void OnDestroy() override;

			ST(const Bullet_Paramater& p, std::unique_ptr<Bullet_Resource>& resource, BulletController& b, EnemyController& e);
			~ST() = default;
		};
	}
}
