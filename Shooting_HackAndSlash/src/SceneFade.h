#pragma once
#include"AbstructScene.h"

namespace Shooting_HackAndSlash {
	namespace Scene {
		// �V�[���J�ڑO�̉��o�p
		class Fade : public AbstructScene {
		public:
			Fade(ISceneChangeListener& i);
			~Fade();
		};
	}
}
