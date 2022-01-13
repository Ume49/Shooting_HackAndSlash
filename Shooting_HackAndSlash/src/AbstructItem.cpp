#include"AbstructItem.h"
#include<DxLib.h>

#include"Player.h"
#include"Define.h"
#include"Time.h"

namespace {
	const Vec2 velocity{};

	constexpr float survival_time = 6.f;

	constexpr float collider_radius = 10.f;
}

namespace Shooting_HackAndSlash {
	AbstructItem::AbstructItem(const std::string& path, Player& p, const Vec2& position) :
		AbstructGameObject(),
		photo_handle(path),
		half_size(),
		is_dead(false),
		p(p),
		survival(::survival_time)
	{
		Point temp_size = photo_handle.size();
		half_size = Vec2{ static_cast<float>(temp_size.x),static_cast<float>(temp_size.y) } / 2;
		
		pos = position;
		collider = CircleCollider(pos, ::collider_radius);
	}

	void AbstructItem::display() const {
		DrawGraphF(pos.x - half_size.x, pos.y - half_size.y, photo_handle, TRUE);
#ifdef _DEBUG
		collider.draw();
#endif // _DEBUG
	}

	void AbstructItem::display(double rate) const {
		DrawRotaGraphF(pos.x, pos.y, rate, Define::RotaGraph_Default::Angle, photo_handle, TRUE);
#ifdef _DEBUG
		collider.draw();
#endif // _DEBUG
	}

	void AbstructItem::update() {
		// �ړ�
		pos += ::velocity * Time::DeltaTime();
		collider.OnPositionChanged(pos);

		// �v���C���[�ƐڐG���Ă��邩�m�F
		if (collider.isColide(p.collider)) {
			// �v���C���[�ƐG�����̂ŏ���
			is_dead = true;

			OnCollide(p);
		}

		// �������Ԃ̏I�����`�F�b�N
		// OnCollide�ŏ����������Ȃ��悤�ɂ������̂ŁA���̌�ɏ����Ă���
		if (survival.is_end()) {
			is_dead = true;
		}
	}
}