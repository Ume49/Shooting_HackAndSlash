#pragma once
#include"AbstructBullet.h"
#include"Photo_SharedHandle.h"
#include"Vector.h"

namespace Shooting_HackAndSlash {
	class Player_Bullet : public AbstructBullet{
	protected:
		// メイン処理
		void _update() override;
	public:
		Player_Bullet();
		~Player_Bullet() = default;
	};
}
