#pragma once

#include"AbstructGameObject.h"

#include"CircleCollider.h"
#include"PhotoDisplayer.h"
#include"Vector.h"
#include"SE_Player.h"

#include<memory>

namespace Shooting_HackAndSlash {
	class Player;
	class AbstructEnemy : public AbstructGameObject {
	protected:
		Player& player_ref;

		// 各ステータス
		int hp, atk;
		// エネミーが向いている方向
		Vec2 direction;

		PhotoDisplayer displayer;

		SE_Player sound;
	public:
		CircleCollider collider;
		bool is_dead;
		bool is_hp_zero() const;
		void Damage(int damage);

		void draw() const override;

		AbstructEnemy(const std::string& photo_path, Player& p);
		virtual ~AbstructEnemy() = default;
	};
}
