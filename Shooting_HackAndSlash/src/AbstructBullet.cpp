#include"AbstructBullet.h"
#include<DxLib.h>
#include"EnemyController.h"
#include"BulletController.h"
#include"AbstructEnemy.h"

#include"Time.h"

namespace Shooting_HackAndSlash {
	AbstructBullet::AbstructBullet(const std::string& path, const Bullet_Paramater& para, std::unique_ptr<Bullet_Resource>& r, EnemyController& e, BulletController& b) :
		velocity(para.direction),
		damage(para.damage),
		is_dead(false),
		is_destroy(true),
		collider(),
		photo(path),
		resource(),
		enemies_ref(e),
		bulletcontroller_ref(b)
	{
		// ���\�[�X�󂯎��
		this->resource = std::move(r);

		// ���W��n��
		pos = para.pos;
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