#include "EnemyController.h"

#include"Enemy_Kusozako.h"
#include<algorithm>
#include<vector>
#include"Player.h"
#include"Stage_Info.h"

#include"ItemController.h"

namespace Shooting_HackAndSlash {
	EnemyController::EnemyController(Player& p, ItemController& i) :
		container(),
		player(p),
		item(i) {
	}

	void EnemyController::update() {
		// 各エネミーを行動させる
		for (auto& w : container) {
			w->update();

			// エネミーと接触したらダメージ
			if (w->collider.isColide(player.collider)) {
				player.Crush();

				w->is_dead = true;
			}
		}

		{	// 死亡判定の出ているエネミーは削除
			// 実際に消す前に、何体死んだのかをステージ情報に報告
			for (auto& w : container) {
				if (w->is_dead) {
					// エネミー死亡報告
					Stage_Info::Call_Enemy_Kill();
					// アイテムの湧出通知
					item.call_spawn(w->pos);
				}
			}

			// 死亡しているエネミーを削除
			container.remove_if([](Enemy_Ptr& w) {return w->is_dead; });
		}
	}

	void EnemyController::draw() const {
		for (auto& w : container) {
			w->draw();
		}
	}

	void EnemyController::Make(const Vec2& spawn_pos, const eEnemy& enemy) {
		switch (enemy) {
		case eEnemy::Kusozako:
			container.push_back(std::make_unique<Enemy::Kusozako>(player, spawn_pos));
			break;
		case eEnemy::Kaiten:
			// 後で作る
			break;
		default:
			break;
		}
	}

	EnemyController::Enemy_Ref_List EnemyController::Collide(const CircleCollider& c) {
		std::vector<std::reference_wrapper<Enemy_Ptr>> e;

		for (auto& w : container) {
			if (w->collider.isColide(c)) {
				e.push_back(w);
			}
		}

		return e;
	}
}