#include"Player_Bullet.h"

#include"BulletController_Player.h"
#include"AbstructEnemy.h"

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
		is_dead = true;

		enemy.Damage(damage);

		controller_ref.Make(pos, move_direction, 1.0f, damage, resource - 1);
	}
}