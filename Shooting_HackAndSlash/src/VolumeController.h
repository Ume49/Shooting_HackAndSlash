#pragma once
#include"Volume.h"
#include"Vector.h"

#include"Photo_SharedHandle.h"
#include"Font_SharedHandle.h"

#include<vector>
#include<memory>
#include<utility>

namespace Shooting_HackAndSlash {
	class VolumeController {
		std::vector <std::unique_ptr<Volume>> container;

		std::vector<std::pair<std::string, Point>> texts;

		Font_SharedHandle font;

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
