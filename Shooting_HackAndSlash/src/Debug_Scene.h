#pragma once
#include"AbstructScene.h"
#include"ButtonController.h"

// ��������掩�R��#include���Ă悢
#include"Gun_Custamize_Window.h"
#include"BackGround_BigStar.h"
#include<vector>

#include"VolumeController.h"

namespace Shooting_HackAndSlash {
	namespace Scene {
		// �P�̃e�X�g�Ƃ����s��������
		class Debug_Scene : public AbstructScene {
			ButtonController buttons;

			VolumeController volume_controller;
		public:
			bool update() override;
			void draw() const override;

			Debug_Scene(ISceneChangeListener& i);
			~Debug_Scene() = default;
		private:
		};
	}
}
