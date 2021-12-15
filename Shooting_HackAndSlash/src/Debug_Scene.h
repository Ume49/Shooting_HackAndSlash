#pragma once
#include"AbstructScene.h"
#include"ButtonController.h"

#include"VolumeController.h"

#include"Fade.h"

#include"BackPack.h"

namespace Shooting_HackAndSlash {
	namespace Scene {
		// �P�̃e�X�g�Ƃ����s��������
		class Debug_Scene : public AbstructScene {
			ButtonController buttons;
			Fade fade;

			BackPack backpack;
		public:
			bool update() override;
			void draw() const override;

			Debug_Scene(ISceneChangeListener& i);
			~Debug_Scene() = default;
		private:
			VolumeController v;
		};
	}
}
