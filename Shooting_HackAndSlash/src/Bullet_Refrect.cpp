#include "Bullet_Refrect.h"

#include"Define.h"

#include"AbstructEnemy.h"
#include"BulletController.h"

namespace {
	using namespace Shooting_HackAndSlash::Define::Window::PlayArea;

	constexpr float x_min = Start::Xf, x_max = End::Xf;
	constexpr float y_min = Start::Yf, y_max = End::Yf;

	constexpr float survival_time = 6.f;

	constexpr float collider_radius = 10.f;

	constexpr float speed = 1280.f;
}

namespace Shooting_HackAndSlash::Bullet {
	Refrect::Refrect(_Bullet_Args_Template) :
		AbstructBullet(Define::Path::Photo::Bullet, p, resource, e, b),
		survival(::survival_time) {
		collider = CircleCollider(pos, ::collider_radius);

		velocity = p.direction * ::speed;
	}

	void Refrect::_update() {
		// �͈͊O�ł��邩�ǂ������ׂ�֐�
		auto is_out = [](float value, float max, float min) {
			return value < min || max < value;
		};

		// x�������]
		if (is_out(pos.x, ::x_max, ::x_min)) {
			velocity.x *= -1.f;
		}
		// y�������]
		if (is_out(pos.y, ::y_max, ::y_min)) {
			velocity.y *= -1.f;
		}

		// �������Ԃ��I�����������
		if (survival.is_end()) {
			is_dead = true;
			is_destroy = false;
		}
	}

	void Refrect::OnCollide(AbstructEnemy& e) {
		is_dead = true;
		is_destroy = true;

		e.Damage(damage);
	}

	void Refrect::OnDestroy() {
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