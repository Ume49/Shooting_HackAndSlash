#pragma once

#include"AbstructGameObject.h"
#include"CircleCollider.h"
#include"PhotoDisplayer.h"


namespace Shooting_HackAndSlash {
	class EnemyController;
	class AbstructEnemy;

	// �摜�̕`��A�ړ��A�_���[�W�ێ��A�ړ��A�Փ˔�����s��
	class AbstructBullet : public AbstructGameObject {
	protected:
		// �ړ����x
		Vec2 velocity;
		// �e���ێ�����_���[�W
		int damage;
		// ����܂ŕ���ł��邩�A�Ƃ�����
		int resource;
		// �����ڕ\����
		PhotoDisplayer photo;

		EnemyController& enemies_ref;

		// �X�V����
		virtual void _update() = 0;

		// �G�l�~�[�ƏՓ˂������̏���
		virtual void OnCollide(AbstructEnemy& enemy) = 0;
	public:
		bool is_dead;
		CircleCollider collider;

		void update() override;
		void draw() const override;

		// �I�u�W�F�N�g����������钼�O�ɌĂ΂�鏈��
		virtual void OnDestroy() {}

		AbstructBullet(const std::string& photo_path, EnemyController& e);
		AbstructBullet(const Photo_SharedHandle& p, EnemyController& e);
		virtual ~AbstructBullet() = default;
	};
}
