#include"Bullet_ST.h"

#include"BulletController.h"
#include"AbstructEnemy.h"

#include"Define.h"
#include"Gun_Info.h"
#include"Time.h"

namespace {
	// �����蔻��̑傫��
	constexpr float collider_radius = 10.f;

	// �ړ����x
	constexpr float speed = 1280.f;

	// ���x�̌����x
	constexpr float resistance = 0.99f;

	// ��������
	constexpr float survival_count = 0.7f;
}

namespace Shooting_HackAndSlash::Bullet {
	ST::ST(const Bullet_Paramater& p, std::unique_ptr<Bullet_Resource>& resource, BulletController& b, EnemyController& e) :
		AbstructBullet(Define::Path::Photo::Bullet, p, resource, e, b),
		survival_count(::survival_count)
	{
		collider = CircleCollider(this->pos, ::collider_radius);

		this->velocity = p.direction * ::speed;
	}

	void ST::_update() {
		// ����������
		velocity = velocity * ::resistance;

		// �������Ԃ��X�V
		this->survival_count -= Time::DeltaTime();

		if (this->survival_count <= 0.f) {
			is_dead = true;
			is_destroy = false;
		}
	}

	void ST::OnCollide(AbstructEnemy& enemy) {
		is_dead = true;

		enemy.Damage(damage);
	}

	void ST::OnDestroy() {
		//���̒e���o��

		// ��������e���擾
		eBullet bullet = resource->get();

		// �����p�����[�^���쐬
		Bullet_Paramater para;

		// �p�����[�^�ݒ�
		para.direction = this->velocity.nomalize();
		para.damage = this->damage;
		para.pos = this->pos;

		// ����
		this->bulletcontroller_ref.Make(bullet, para, resource);
	}
}