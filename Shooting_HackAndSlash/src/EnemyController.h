#pragma once

#include<list>
#include<memory>
#include"AbstructEnemy.h"
#include"Vector.h"
#include<vector>
#include"eEnemy.h"


namespace Shooting_HackAndSlash {
	class Player;
	class ItemController;
	class EnemyController {
	public:
		using Enemy_Ptr = std::unique_ptr<AbstructEnemy>;
		using Enemy_List = std::list<Enemy_Ptr>;
		using Enemy_Ref_List = std::vector<std::reference_wrapper<Enemy_Ptr>>;
	private:
		Player& player;
		ItemController& item;
		Enemy_List container;
	public:
		void update();
		void draw() const;

		void Make(const Vec2& spawn_pos, const eEnemy& enemy);

		// 判定と衝突しているエネミーのポインタ集を返す
		Enemy_Ref_List Collide(const CircleCollider& c);

		EnemyController(Player& p, ItemController& i);
		~EnemyController() = default;
	};
}
