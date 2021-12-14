#pragma once

#include"Photo_SharedHandle.h"
#include"Vector.h"

namespace Shooting_HackAndSlash {
	class Gauge {
	private:
		Point pos;
		Point photo_size;
		Photo_SharedHandle photo_handle;
		// ‹ó”’‚Ì’·‚³‚ðŒvŽZ‚µ‚Ä•Ô‚·
		int get_voidLength(float value) const;
	public:

		void draw(float value) const;

		Gauge(const std::string& path, const Point& p);
		~Gauge() = default;
	};
}