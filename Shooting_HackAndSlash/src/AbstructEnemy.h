#pragma once

#include"AbstructGameObject.h"

#include"CircleCollider.h"
#include"PhotoDisplayer.h"
#include"Vector.h"

#include<memory>

namespace Shooting_HackAndSlash {
	class Player;
	class AbstructEnemy : public AbstructGameObject {
	protected:
		Player& player_ref;

		int hp, atk;
		Vec2 velocity;

		PhotoDisplayer displayer;

		virtual void _update() = 0;
	public:
		CircleCollider collider;
		bool is_dead;
		void Damage(int damage);

		void update() override;
		void draw() const override;

		AbstructEnemy(const std::string& photo_path, Player& p);
		virtual ~AbstructEnemy() = default;
	};
}
