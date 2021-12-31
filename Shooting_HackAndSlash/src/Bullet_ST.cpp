#include"Bullet_ST.h"

#include"BulletController.h"
#include"AbstructEnemy.h"

#include"Define.h"
#include"Gun_Info.h"

namespace {
	// �����蔻��̑傫��
	constexpr float collider_radius = 10.f;

	// �ړ����x
	constexpr float speed = 640.f;
}

namespace Shooting_HackAndSlash::Bullet {
	ST::ST(const Bullet_Paramater& p, BulletController& b, EnemyController& e) :
		AbstructBullet(Define::Path::Photo::Bullet, e),
		controller_ref(b)
	{
		damage = p.damage;
		velocity = p.direction * ::speed;
		pos = p.pos;
		resource = p.resource;
		collider = CircleCollider(pos, ::collider_radius);
	}

	void ST::_update() {
	}

	void ST::OnCollide(AbstructEnemy& enemy) {
		is_dead = true;

		enemy.Damage(damage);
	}

	void ST::OnDestroy() {
		//���̒e���o��

		// ���\�[�X�������̂ł���ΏI��
		if (resource == 0) return;

		// ���\�[�X���琶������e�̃C���f�b�N�X���擾
		// *�o�O���邩��
		int temp_index = Gun_Info::get_resource() - this->resource;

		// ��������e���擾
		eBullet b = Gun_Info::Now_Gun().magazine.at(temp_index);

		// �����p�����[�^���쐬
		Bullet_Paramater temp_para;

		// �p�����[�^�ݒ�
		temp_para.direction = this->velocity.nomalize();
		temp_para.damage = this->damage;
		temp_para.bullet = b;
		temp_para.pos = this->pos;
		temp_para.resource = this->resource - 1;

		// ����
		this->controller_ref.Make(temp_para);
	}
}