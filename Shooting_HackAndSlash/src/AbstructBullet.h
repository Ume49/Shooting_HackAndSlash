#pragma once

#include"AbstructGameObject.h"
#include"CircleCollider.h"
#include"PhotoDisplayer.h"
#include"Bullet_Paramater.h"
#include"Bullet_Resource.h"

#include<memory>

#define _Bullet_Args_Template const Bullet_Paramater& p, std::unique_ptr<Bullet_Resource>& resource, BulletController& b, EnemyController& e

namespace Shooting_HackAndSlash {
	class EnemyController;
	class AbstructEnemy;
	class BulletController;

	// �摜�̕`��A�ړ��A�_���[�W�ێ��A�ړ��A�Փ˔�����s��
	class AbstructBullet : public AbstructGameObject {
	protected:
		// �ړ����x
		Vec2 velocity;
		// �e���ێ�����_���[�W
		int damage;
		// �����ڕ\����
		PhotoDisplayer photo;

		// ��������i�[���Ă������\�[�X
		std::unique_ptr<Bullet_Resource> resource;

		EnemyController& enemies_ref;
		BulletController& bulletcontroller_ref;

		// �X�V����
		virtual void _update() = 0;

		// �G�l�~�[�ƏՓ˂������̏���
		virtual void OnCollide(AbstructEnemy& enemy) = 0;
	public:
		// �����邩�ǂ���
		bool is_dead;
		// ������Ƃ��AOnDestroy���Ăяo�����ǂ���
		bool is_destroy;
		CircleCollider collider;

		void update() override;
		void draw() const override;

		// �I�u�W�F�N�g����������钼�O�ɌĂ΂�鏈��
		virtual void OnDestroy() {}

		AbstructBullet(const std::string& path, const Bullet_Paramater& para, std::unique_ptr<Bullet_Resource>& r, EnemyController& e, BulletController& b);
		virtual ~AbstructBullet() = default;
	};
}
