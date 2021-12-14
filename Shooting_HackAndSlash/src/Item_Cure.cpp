#include "Item_Cure.h"
#include"Define.h"
#include<DxLib.h>
#include"Player.h"
#include"PlayerInfo.h"
#include"Time.h"

namespace {
	constexpr float survival_time = 5.f;
	constexpr float collider_radius = 10.f;
	// �񕜗�
	const int cure_point = 10;
}

namespace PATH = Shooting_HackAndSlash::Define::Path::Photo;

namespace Shooting_HackAndSlash::Item {
	Cure::Cure(const Vec2& p, Player& pl) :
		AbstructItem(PATH::Cristal),
		survival_time(::survival_time),
		ref_player(pl)
	{
		pos = p;
		collider = CircleCollider(pos, ::collider_radius);
	}

	void Cure::update() {
		// �v���C���[�Ƃ̏Փ˔���
		if (collider.isColide(ref_player.collider)) {
			// �v���C���[���񕜂��āA���̃A�C�e���͏���
			PlayerInfo::Cure(cure_point);

			is_dead = true;
		}

		// �������Ԃ��I�����������
		if ((survival_time -= Time::DeltaTime()) <= 0.f) {
			is_dead = true;
		}
	}

	void Cure::draw() const {
		// �����ڂ�`��
		display();
	}
}