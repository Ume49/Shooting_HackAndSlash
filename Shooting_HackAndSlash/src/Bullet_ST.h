#pragma once
#include"AbstructBullet.h"

namespace Shooting_HackAndSlash {
	namespace Bullet {
		// ���i����
		class ST : public AbstructBullet {
		private:
			// ��������
			float survival_count;

		protected:
			// ���C������
			void _update() override;

			// �����������̏���
			void OnCollide(AbstructEnemy& enemy) override;
		public:
			// ���ʂƂ��̏���
			void OnDestroy() override;

			ST(const Bullet_Paramater& p, std::unique_ptr<Bullet_Resource>& resource, BulletController& b, EnemyController& e);
			~ST() = default;
		};
	}
}
