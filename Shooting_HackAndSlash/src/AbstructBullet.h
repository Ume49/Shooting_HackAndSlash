#pragma once

#include"AbstructGameObject.h"
#include"CircleCollider.h"
#include"PhotoDisplayer.h"

namespace Shooting_HackAndSlash {
	class AbstructBullet : public AbstructGameObject {
	protected:
		Vec2 move_direction;
		int damage;
		PhotoDisplayer photo;

		virtual void _update() = 0;
	public:
		bool is_dead;
		CircleCollider collider;

		void update() override;
		void draw() const override;

		AbstructBullet(const std::string& photo_path);
		virtual ~AbstructBullet() = default;
	};
}
