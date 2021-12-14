#pragma once

#include"Abstruct_UI.h"
#include"Bullet_Lancher.h"
#include"Vector.h"
#include"Gauge.h"
#include"Photo_SharedHandle.h"

namespace Shooting_HackAndSlash {
	namespace  UI {
		class Bullet_CoolTime_Displayer : public Abstruct_UI {
		private:
			const Bullet_Lancher& bullet_lancher;
			Gauge gauge;
			Photo_SharedHandle frame_handle;
			Photo_SharedHandle backgr_handle;
		public:
			void draw() const override;

			Bullet_CoolTime_Displayer(const Bullet_Lancher& b);
			~Bullet_CoolTime_Displayer() = default;
		};
	}
}