#include"Bullet_V.h"
#include"BulletController.h"

#include<cmath>
#include<numbers>

#include"Define.h"

namespace {
	// ���˂�����̒e�ۂ��ׂ��p�x
	// ���̌v�Z���͓x���@�����W�A���\�L�ɕϊ����邽�߂̎�
	constexpr float v_angle = 30.f * static_cast<float>(std::numbers::pi) / 180.f;

	constexpr int	launch_count	= 2;		// ���˂����
	constexpr float damage_decrease = 0.8f;		// �_���[�W������
}

namespace Shooting_HackAndSlash::Bullet {
	V::V(const Bullet_Paramater& p, std::unique_ptr<Bullet_Resource>& resource, BulletController& b, EnemyController& e) :
		AbstructBullet(Define::Path::Photo::Bullet, p, resource, e, b) {
		// �������������悤�ɂ���
		this->is_dead		= true;
		this->is_destroy	= true;

		// �_���[�W����
		this->damage = static_cast<int>(p.damage * ::damage_decrease);
	}

	void V::OnCollide(AbstructEnemy& e) {}	// �������Ȃ�

	void V::_update() {}	// �������Ȃ�

	void V::OnDestroy() {
		Bullet_Paramater para;

		// �p�����[�^�̐ݒ�
		para.damage = this->damage;
		para.pos	= this->pos;

		// �e�擾
		eBullet bullet = resource->get();

		// ���݂̊p�x���擾
		float now_angle = std::atan2f(velocity.y, velocity.x);

		// �����̊p�x���v�Z
		float left_angle = now_angle - ::v_angle / 2.f;
		// �E���̊p�x���v�Z
		// �v�Z���\�[�X���P�`�邽�߂ɍ����̊p�x���狁�߂�
		float right_angle = left_angle + ::v_angle;

		// �e�쐬�֐�
		auto make = [&](float angle) {
			// ����
			Vec2 direction;

			// x��y���������ꂼ�ꋁ�߂�
			direction.x = std::cosf(angle);
			direction.y = std::sinf(angle);

			// ���
			para.direction = direction;

			// ���\�[�X�̕���
			std::unique_ptr<Bullet_Resource> r(std::make_unique<Bullet_Resource>(*resource));

			// �쐬
			bulletcontroller_ref.Make(bullet, para, r);
		};

		// �����
		make(left_angle);
		make(right_angle);
	}
}