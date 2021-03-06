#pragma once

#include"Photo_SharedHandle.h"
#include"Vector.h"

namespace Shooting_HackAndSlash {
	class Gauge {
	private:
		Point pos;
		Point photo_size;
		Photo_SharedHandle photo_handle;
		// 空白の長さを計算して返す
		int get_voidLength(float value) const;
	public:

		void draw(float value) const;

		Gauge(const std::string& path, const Point& p);
		~Gauge() = default;
	};
}