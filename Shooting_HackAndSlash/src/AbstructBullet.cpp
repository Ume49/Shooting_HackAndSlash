#include"AbstructBullet.h"
#include<DxLib.h>
#include"EnemyController.h"

#include"Time.h"

namespace Shooting_HackAndSlash {
	AbstructBullet::AbstructBullet(const std::string& photo_path, EnemyController& e) :
		move_direction(),
		damage(),
		is_dead(false),
		collider(),
		photo(photo_path),
		enemies_ref(e)
	{
	}

	void AbstructBullet::update() {
		// �ړ�
		pos += move_direction * Time::DeltaTime();
		collider.OnPositionChanged(pos);

		// �Փ˂��Ă���G�l�~�[�̃��X�g���擾
		auto list = enemies_ref.Collide(collider);

		// �Փ˂����G�l�~�[�̐������A�ŗL�̏������Ăяo��
		for (auto& w : list) {
			OnCollide(*w.get());
		}

		_update();
	}

	void AbstructBullet::draw() const {
		photo.display(pos, move_direction);

#ifdef _DEBUG
		collider.draw();
#endif // _DEBUG
	}
}