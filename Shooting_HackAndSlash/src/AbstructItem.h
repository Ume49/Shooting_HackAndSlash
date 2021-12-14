#pragma once
#include"AbstructGameObject.h"
#include"Photo_SharedHandle.h"
#include"CircleCollider.h"

namespace Shooting_HackAndSlash {
	class AbstructItem : public AbstructGameObject{
	private:
		Photo_SharedHandle photo_handle;
		Vec2 half_size;
	protected:
		CircleCollider collider;

		// Œ©‚½–Ú‚Ì•`‰æ
		void display() const;
	public:
		bool is_dead;

		AbstructItem(const std::string& path);
		virtual ~AbstructItem() = default;
	};
}
