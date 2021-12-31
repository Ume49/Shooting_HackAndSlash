#pragma once
#include"AbstructBullet.h"
#include"Photo_SharedHandle.h"
#include"Vector.h"
#include"Bullet_Paramater.h"

namespace Shooting_HackAndSlash {
	class BulletController;
	namespace Bullet {
		// ���i����
		class ST : public AbstructBullet {
		private:
			BulletController& controller_ref;
		protected:
			// ���C������
			void _update() override;

			// �����������̏���
			void OnCollide(AbstructEnemy& enemy) override;
		public:
			// ���ʂƂ��̏���
			void OnDestroy() override;

			ST(const Bullet_Paramater& p, BulletController& b, EnemyController& e);
			~ST() = default;
		};
	}
}
