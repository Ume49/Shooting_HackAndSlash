#include"AbstructBullet.h"
#include<DxLib.h>
#include"EnemyController.h"

#include"Time.h"

namespace Shooting_HackAndSlash {
	AbstructBullet::AbstructBullet(const std::string& photo_path, EnemyController& e) :
		velocity(),
		damage(),
		is_dead(false),
		collider(),
		photo(photo_path),
		resource(0),
		enemies_ref(e)
	{
	}

	AbstructBullet::AbstructBullet(const Photo_SharedHandle& p, EnemyController& e) :
		velocity(),
		damage(),
		is_dead(false),
		collider(),
		photo(p),
		resource(0),
		enemies_ref(e)
	{
	}

	void AbstructBullet::update() {
		// �ړ�
		pos += velocity * Time::DeltaTime();
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
		photo.display(pos, velocity);

#ifdef _DEBUG
		collider.draw();
#endif // _DEBUG
	}
}