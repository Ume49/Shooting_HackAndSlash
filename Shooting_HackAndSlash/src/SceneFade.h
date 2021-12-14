#pragma once
#include"AbstructScene.h"

namespace Shooting_HackAndSlash {
	namespace Scene {
		// シーン遷移前の演出用
		class Fade : public AbstructScene {
		public:
			Fade(ISceneChangeListener& i);
			~Fade();
		};
	}
}
