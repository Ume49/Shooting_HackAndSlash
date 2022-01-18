#include "EnemyController.h"

#include"Enemy_Kusozako.h"
#include<algorithm>
#include<vector>
#include"Player.h"
#include"Stage_Info.h"

#include"ItemController.h"

namespace Shooting_HackAndSlash {
	EnemyController::EnemyController(Player& p, ItemController& i) :
		container(),
		player(p),
		item(i) {
	}

	void EnemyController::update() {
		// �e�G�l�~�[���s��������
		for (auto& w : container) {
			w->update();

			// �G�l�~�[�ƐڐG������_���[�W
			if (w->collider.isColide(player.collider)) {
				player.Crush();

				w->is_dead = true;
			}
		}

		{	// ���S����̏o�Ă���G�l�~�[�͍폜
			// ���ۂɏ����O�ɁA���̎��񂾂̂����X�e�[�W���ɕ�
			for (auto& w : container) {
				if (w->is_dead) {
					// �G�l�~�[���S��
					Stage_Info::Call_Enemy_Kill();
					// �A�C�e���̗N�o�ʒm
					item.call_spawn(w->pos);
				}
			}

			// ���S���Ă���G�l�~�[���폜
			container.remove_if([](Enemy_Ptr& w) {return w->is_dead; });
		}
	}

	void EnemyController::draw() const {
		for (auto& w : container) {
			w->draw();
		}
	}

	void EnemyController::Make(const Vec2& spawn_pos, const eEnemy& enemy) {
		switch (enemy) {
		case eEnemy::Kusozako:
			container.push_back(std::make_unique<Enemy::Kusozako>(player, spawn_pos));
			break;
		case eEnemy::Kaiten:
			// ��ō��
			break;
		default:
			break;
		}
	}

	EnemyController::Enemy_Ref_List EnemyController::Collide(const CircleCollider& c) {
		std::vector<std::reference_wrapper<Enemy_Ptr>> e;

		for (auto& w : container) {
			if (w->collider.isColide(c)) {
				e.push_back(w);
			}
		}

		return e;
	}
}