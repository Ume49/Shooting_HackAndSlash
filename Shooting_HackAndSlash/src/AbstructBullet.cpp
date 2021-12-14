#include"AbstructBullet.h"
#include"Time.h"
#include<DxLib.h>

namespace Shooting_HackAndSlash {
	AbstructBullet::AbstructBullet(const std::string& photo_path) :
		move_direction(),
		damage(),
		is_dead(false),
		collider(),
		photo(photo_path) {
	}

	void AbstructBullet::update() {
		pos += move_direction * Time::DeltaTime();
		collider.OnPositionChanged(pos);

		_update();
	}

	void AbstructBullet::draw() const {
		photo.display(pos, move_direction);

#ifdef _DEBUG
		collider.draw();
#endif // _DEBUG
	}
}