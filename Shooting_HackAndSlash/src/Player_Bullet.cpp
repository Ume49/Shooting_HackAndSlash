#include"Player_Bullet.h"

#include"BulletController_Player.h"

#include"Define.h"
#include"Gun_Info.h"

namespace Shooting_HackAndSlash {
	Player_Bullet::Player_Bullet(int r, BulletController_Player& b, EnemyController& e) :
		AbstructBullet(Define::Path::Photo::Bullet, e),
		controller_ref(b),
		resource(r)
	{
	}

	void Player_Bullet::_update() {
	}
	void Player_Bullet::OnCollide(AbstructEnemy& enemy) {
	}
}