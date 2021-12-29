#pragma once

#include"AbstructGameObject.h"
#include"CircleCollider.h"
#include"PhotoDisplayer.h"


namespace Shooting_HackAndSlash {
	class EnemyController;
	class AbstructEnemy;
	class AbstructBullet : public AbstructGameObject {
	protected:
		Vec2 move_direction;
		int damage;
		PhotoDisplayer photo;

		EnemyController& enemies_ref;

		// 更新処理
		virtual void _update() = 0;

		// エネミーと衝突した時の処理
		virtual void OnCollide(AbstructEnemy& enemy) = 0;
	public:
		bool is_dead;
		CircleCollider collider;

		void update() override;
		void draw() const override;

		AbstructBullet(const std::string& photo_path, EnemyController& e);
		virtual ~AbstructBullet() = default;
	};
}
