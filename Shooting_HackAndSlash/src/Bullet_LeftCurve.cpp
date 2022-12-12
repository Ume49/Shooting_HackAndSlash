#include "Bullet_LeftCurve.h"

#include"BulletController.h"
#include"AbstructEnemy.h"

#include"Define.h"
#include"Vec2_Rotate.h"

#include"Time.h"

namespace {
	constexpr float survival_count	= 3.f;
	
	constexpr float curve_rength	= 3000.f;	// �Ȃ���͂̑傫��

	constexpr float collider_radius = 10.f;

	constexpr float speed			= 1280.f;
}

namespace Shooting_HackAndSlash::Bullet {
	LeftCurve::LeftCurve(_Bullet_Args_Template) :
		AbstructBullet(Define::Path::Photo::Bullet, p, resource, e, b),
		survival(::survival_count) {
		collider = CircleCollider(pos, ::collider_radius);
		
		// ���x�����߂�
		velocity = p.direction * ::speed;
	}

	void LeftCurve::_update() {
		// �i�s�����ɑ΂��ĉE���̃x�N�g�������
		auto force = Vec2_Rotate(velocity, Degree_to_Radian(-90.f)).nomalize() * ::curve_rength * Time::DeltaTime();

		// �K�p����
		velocity += force;

		// ����
		if (survival.is_end()) {
			is_dead = true;
		}
	}

	void LeftCurve::OnCollide(AbstructEnemy& e) {
		is_dead		= true;
		is_destroy	= true;

		e.Damage(damage);
	}

	void LeftCurve::OnDestroy() {
		//���̒e���o��

		// ��������e���擾
		eBullet bullet = resource->get();

		// �����p�����[�^���쐬
		Bullet_Paramater para;

		// �p�����[�^�ݒ�
		para.direction	= this->velocity.nomalize();
		para.damage		= this->damage;
		para.pos		= this->pos;

		// ����
		this->bulletcontroller_ref.Make(bullet, para, resource);
	}
}