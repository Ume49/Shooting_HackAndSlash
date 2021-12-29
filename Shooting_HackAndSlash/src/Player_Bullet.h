#pragma once
#include"AbstructBullet.h"
#include"Photo_SharedHandle.h"
#include"Vector.h"

namespace Shooting_HackAndSlash {
	class BulletController_Player;
	class Player_Bullet : public AbstructBullet{
	private:
		// 何回まで分岐できるのか
		int resource;

		BulletController_Player& controller_ref;
	protected:
		// メイン処理
		void _update() override;

		// 当たった時の処理
		void OnCollide(AbstructEnemy& enemy) override;
	public:
		Player_Bullet(int resource ,BulletController_Player& b, EnemyController& e);
		~Player_Bullet() = default;
	};
}
