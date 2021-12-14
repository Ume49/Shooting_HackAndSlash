#pragma once

#include"AbstructScene.h"
#include"ButtonController.h"

#include<DxLib.h>

namespace Shooting_HackAndSlash {
	namespace Scene {
		// �ǂ̃V�[���ɍs���̂��I������A�f�o�b�O���[�h��p�V�[��
		class Debug_Choice : public AbstructScene {
		private:
			bool is_quit;
			ButtonController buttons;
		public:
			bool update() override;

			void draw() const;

			Debug_Choice(ISceneChangeListener& i);
			~Debug_Choice() = default;
		};
	}
}