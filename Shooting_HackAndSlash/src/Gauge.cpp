#include "Gauge.h"
#include<cassert>
#include<DxLib.h>

namespace Shooting_HackAndSlash {
	Gauge::Gauge(const std::string& path, const Point& p) :
		pos(p),
		photo_size(),
		photo_handle(path) {
		GetGraphSize(photo_handle, &photo_size.x, &photo_size.y);
	}

	int Gauge::get_voidLength(float v) const {
		float void_value = 1.f - v;

		return static_cast<int>(void_value * photo_size.y);
	}

	void Gauge::draw(float v) const {
		assert(v >= 0.f && v <= 1.f);

		// ‹ó”’‚Ì‘å‚«‚³
		int void_length = get_voidLength(v);

		DrawRectGraph(pos.x, pos.y + void_length, 0, void_length, photo_size.x, photo_size.y - void_length, photo_handle, TRUE);
	}
}