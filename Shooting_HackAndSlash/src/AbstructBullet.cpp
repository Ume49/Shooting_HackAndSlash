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
		// リソース受け取り
		this->resource = std::move(r);

		// 座標を渡す
		pos = para.pos;
	}

	void AbstructBullet::update() {
		// 移動
		pos += velocity * Time::DeltaTime();
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
		photo.display(pos, velocity);

#ifdef _DEBUG
		collider.draw();
#endif // _DEBUG
	}
}