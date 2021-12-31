#pragma once
#include"AbstructBullet.h"
#include"Photo_SharedHandle.h"
#include"Vector.h"
#include"Bullet_Paramater.h"

namespace Shooting_HackAndSlash {
	class BulletController;
	namespace Bullet {
		// 直進する
		class ST : public AbstructBullet {
		private:
			BulletController& controller_ref;
		protected:
			// メイン処理
			void _update() override;

			// 当たった時の処理
			void OnCollide(AbstructEnemy& enemy) override;
		public:
			// 死ぬときの処理
			void OnDestroy() override;

			ST(const Bullet_Paramater& p, BulletController& b, EnemyController& e);
			~ST() = default;
		};
	}
}
