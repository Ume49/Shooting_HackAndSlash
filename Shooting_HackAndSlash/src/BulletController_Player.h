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
		/// 弾丸生成補助関数
		/// </summary>
		/// <param name="pos">出す場所</param>
		/// <param name="direction">向き</param>
		/// <param name="speed">移動速度</param>
		/// <param name="damage">弾が持つダメージ</param>
		void Make(const Vec2& pos, const Vec2& direction, float speed, int damage);

		BulletController_Player(EnemyController& e) : bullets(), enemy_con(e) {}
		~BulletController_Player() = default;
	};
}