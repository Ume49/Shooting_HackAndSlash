#pragma once
#include"AbstructGameObject.h"
#include"Photo_SharedHandle.h"
#include"CircleCollider.h"
#include"Survival_Counter.h"

namespace Shooting_HackAndSlash {
	class Player;

	class AbstructItem : public AbstructGameObject {
	private:
		Photo_SharedHandle photo_handle;
		Vec2 half_size;
		Survival_Counter survival;

		Player& p;
	protected:
		CircleCollider collider;

		// �����ڂ̕`��
		void display() const;

		// �g��k�����������ꍇ
		void display(double ex_rate) const;

		virtual void OnCollide(Player& p) = 0;
	public:
		bool is_dead;

		void update() override;

		AbstructItem(const std::string& path, Player& p, const Vec2& pos);
		virtual ~AbstructItem() = default;
	};
}
