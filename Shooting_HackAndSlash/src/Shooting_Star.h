#pragma once

#include"Vector.h"

#include<list>

namespace Shooting_HackAndSlash::BackGround_Object {
	class Shooting_Stars {
		class Star {
			Vec2 pos;
		public:
			void update();
			void draw() const;

			bool is_stage_out() const;

			Star(const Vec2& init_pos);
			~Star() = default;
		};


		std::list<Star> container;

		float counter;
	public:
		void update();
		void draw() const;

		Shooting_Stars();
		~Shooting_Stars() = default;
	};
}
