#pragma once

#include"AbstructGameObject.h"
#include"CircleCollider.h"
#include"PhotoDisplayer.h"
#include"Bullet_Paramater.h"
#include"Bullet_Resource.h"

#include<memory>

#define _Bullet_Args_Template const Bullet_Paramater& p, std::unique_ptr<Bullet_Resource>& resource, BulletController& b, EnemyController& e

namespace Shooting_HackAndSlash {
	class EnemyController;
	class AbstructEnemy;
	class BulletController;

	// 画像の描画、移動、ダメージ保持、移動、衝突判定を行う
	class AbstructBullet : public AbstructGameObject {
	protected:
		// 移動速度
		Vec2 velocity;
		// 弾が保持するダメージ
		int damage;
		// 見た目表示器
		PhotoDisplayer photo;

		// 分岐情報を格納しておくリソース
		std::unique_ptr<Bullet_Resource> resource;

		EnemyController& enemies_ref;
		BulletController& bulletcontroller_ref;

		// 更新処理
		virtual void _update() = 0;

		// エネミーと衝突した時の処理
		virtual void OnCollide(AbstructEnemy& enemy) = 0;
	public:
		// 消えるかどうか
		bool is_dead;
		// 消えるとき、OnDestroyを呼び出すかどうか
		bool is_destroy;
		CircleCollider collider;

		void update() override;
		void draw() const override;

		// オブジェクトが消去される直前に呼ばれる処理
		virtual void OnDestroy() {}

		AbstructBullet(const std::string& path, const Bullet_Paramater& para, std::unique_ptr<Bullet_Resource>& r, EnemyController& e, BulletController& b);
		virtual ~AbstructBullet() = default;
	};
}
