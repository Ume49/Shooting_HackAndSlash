#pragma once
#include"Volume.h"
#include"Vector.h"
#include"Photo_SharedHandle.h"
#include<vector>
#include<memory>

namespace Shooting_HackAndSlash {
	class VolumeController {
		std::vector <std::unique_ptr<Volume>> container;

		struct Back {
			Photo_SharedHandle handle;
			Point pos;
		} back;
	public:
		void update();
		void draw() const;

		VolumeController(const Point& pos);
		~VolumeController() = default;
	};
}
