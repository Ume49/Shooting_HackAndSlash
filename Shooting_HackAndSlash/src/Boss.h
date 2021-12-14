#pragma once
#include "AbstructScene.h"

#include"Photo_SharedHandle.h"

namespace Shooting_HackAndSlash {
	namespace Scene {
		class Boss : public AbstructScene {
		private:
		public:
			Boss(ISceneChangeListener& s);
			~Boss() = default;
			void draw() const override;
			bool update() override;
		};
	}
}