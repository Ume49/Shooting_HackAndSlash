#pragma once

#include<list>
#include<memory>
#include"AbstructBullet.h"
#include"Vector.h"

namespace Shooting_HackAndSlash {
	class EnemyController;
	class BulletController_Player {
	private:
		EnemyController& enemy_con;
		std::list<std::unique_ptr<AbstructBullet>> bullets;
	public:
		void update();
		void draw() const;

		/// <summary>
		/// �e�ې����⏕�֐�
		/// </summary>
		/// <param name="pos">�o���ꏊ</param>
		/// <param name="direction">����</param>
		/// <param name="speed">�ړ����x</param>
		/// <param name="damage">�e�����_���[�W</param>
		void Make(const Vec2& pos, const Vec2& direction, float speed, int damage);

		BulletController_Player(EnemyController& e) : bullets(), enemy_con(e) {}
		~BulletController_Player() = default;
	};
}