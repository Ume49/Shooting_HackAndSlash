#pragma once

#include"Vector"
#include"AbstructGameObject.h"

#include"CircleCollider.h"

#include"Bomb_Launcher.h"
#include"Bullet_Lancher.h"

#include"BulletController_Player.h"

#include<memory>
#include<functional>
#include"IDisplayer.h"

namespace Shooting_HackAndSlash {
	class Player : public AbstructGameObject {
		static constexpr float radius = 12.f;
	private:
		void Move();
		// �Q�[���I�[�o�[����
		void game_over();
		void init();
		// ���񂾂�����
		void judge_death();
	public:
		/// <summary>
		/// �_���[�W�֐�
		/// </summary>
		/// <param name="damage">�^����_���[�W</param>
		/// <returns>�_���[�W��^������HP��0�ɂȂ�Ȃ�false</returns>
		void Damage(int damage);

		// �G�l�~�[�{�̂ƐڐG�������̏���
		void Crush();

		void update() override;
		void draw() const override;

		const Bullet_Lancher& show_bulletlancher() const { return bullet; }
		const Vec2& show_position() const { return pos; }
	public:
		CircleCollider collider;
	private:
		// �����ڂ�\������@�\
		std::unique_ptr<IDisplayer> looks;

		std::function<void(void)> go_result;

		Bomb_Launcher bomb;
		Bullet_Lancher bullet;

		// ���ʕ���
		Vec2 front;
	public:
		Player(BulletController_Player& b, std::function<void()> func_go_result) :
			looks(),
			collider(pos, radius),
			bomb(),
			bullet(b),
			go_result(func_go_result),
			front(0.f,0.f){
			init();
		}
	};
}
