#include "Bullet_RightCurve.h"

#include"BulletController.h"
#include"AbstructEnemy.h"

#include"Define.h"
#include"Vec2_Rotate.h"

#include"Time.h"

namespace {
	constexpr float survival_count	= 10.f;
	
	constexpr float curve_rength	= 3000.f;	// �E�ɋȂ���͂̑傫��

	constexpr float speed			= 1280.f;

	constexpr float collider_radius = 10.f;
}

namespace Shooting_HackAndSlash::Bullet {
	RightCurve::RightCurve(_Bullet_Args_Template) :
		AbstructBullet(Define::Path::Photo::Bullet, p, resource, e, b),
		survival(::survival_count) {
		// ���x������
		velocity = p.direction * ::speed;

		// �����蔻�������
		collider = CircleCollider(pos, ::collider_radius);
	}

	void RightCurve::_update() {
		// �i�s�����ɑ΂��ĉE���̃x�N�g�������
		auto force = Vec2_Rotate(velocity, Degree_to_Radian(90.f)).nomalize() * ::curve_rength * Time::DeltaTime();

		// �K�p����
		velocity += force;

		if (survival.is_end()) {
			is_dead = true;
		}
	}

	void RightCurve::OnCollide(AbstructEnemy& e) {
		is_dead		= true;
		is_destroy	= true;

		e.Damage(damage);
	}

	void RightCurve::OnDestroy() {
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