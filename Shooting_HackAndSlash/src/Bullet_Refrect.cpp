#include "Bullet_Refrect.h"

#include"Define.h"

namespace {
	using namespace Shooting_HackAndSlash::Define::Window::PlayArea;

	constexpr float x_min = Start::Xf, x_max=End::Xf;
	constexpr float y_min = Start::Yf, y_max = End::Yf;
}

namespace Shooting_HackAndSlash::Bullet {
	void Refrect::_update() {
		// 範囲外であるかどうか調べる関数
		auto is_out = [](float value, float max, float min) {
			return value < min || max < value;
		};

		// x方向反転
		if (is_out(pos.x, ::x_max, ::x_min)) {
			velocity.x *= -1.f;
		}
		// y方向反転
		if (is_out(pos.y, ::y_max, ::y_min)) {
			velocity.y *= -1.f;
		}
	}

	void Refrect::OnCollide(AbstructEnemy& e) {
		is_dead = true;
		

	}

	void Refrect::OnDestroy() {

	}
}