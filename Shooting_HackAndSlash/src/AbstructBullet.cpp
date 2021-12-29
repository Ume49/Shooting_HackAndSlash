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
		// 移動
		pos += move_direction * Time::DeltaTime();
		collider.OnPositionChanged(pos);

		// 衝突しているエネミーのリストを取得
		auto list = enemies_ref.Collide(collider);

		// 衝突したエネミーの数だけ、固有の処理を呼び出す
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