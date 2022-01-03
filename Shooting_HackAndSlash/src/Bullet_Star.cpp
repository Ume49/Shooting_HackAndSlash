#include "Bullet_Star.h"

#include<cmath>
#include<numbers>

#include"BulletController.h"
#include"Define.h"

namespace {
	// �_���[�W������
	constexpr float damage_decrease = 0.6f;

	// ��̊p�x
	constexpr float mono_angle = 360.f / 5.f * static_cast<float>(std::numbers::pi) / 180.f;
}

namespace Shooting_HackAndSlash::Bullet {
	Star::Star(const Bullet_Paramater& p, std::unique_ptr<Bullet_Resource>& resource, BulletController& b, EnemyController& e) :
		AbstructBullet(Define::Path::Photo::Bullet, p, resource, e, b)
	{
		// �V�������S������
		this->is_dead = true;
		this->is_destroy = true;

		// �_���[�W�����炷
		this->damage = static_cast<int>(p.damage * ::damage_decrease);
	}

	void Star::_update() { /* �������Ȃ� */ }
	void Star::OnCollide(AbstructEnemy& e) { /* �������Ȃ� */ }

	void Star::OnDestroy() {
		// �e�擾
		eBullet bullet = resource->get();

		// �p�����[�^�쐬
		Bullet_Paramater para;

		para.damage = damage;
		para.pos = pos;

		for (auto i = 0.f; i < 5.f; i++) {
			// �����v�Z
			Vec2 dir;

			float temp_angle = ::mono_angle * i;

			dir.x = std::cosf(temp_angle);
			dir.y = std::sinf(temp_angle);

			para.direction = dir;

			// ���\�[�X����
			std::unique_ptr<Bullet_Resource> rsrc{ std::make_unique<Bullet_Resource>(*resource) };

			// �쐬
			bulletcontroller_ref.Make(bullet, para, rsrc);
		}
	}
}