#pragma once

#include"AbstructGameObject.h"
#include"CircleCollider.h"

#include<memory>
#include"PhotoDisplayer.h"

namespace Shooting_HackAndSlash {
	class AbstructEnemy : public AbstructGameObject {
	protected:
		int hp, atk;
		PhotoDisplayer displayer;
	public:
		CircleCollider collider;
		bool is_dead;
		void Damage(int damage);

		AbstructEnemy(const std::string& photo_path);
		virtual ~AbstructEnemy() = default;
	};
}
