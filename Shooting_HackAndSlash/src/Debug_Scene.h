#pragma once
#include"AbstructScene.h"
#include"ButtonController.h"

// ��������掩�R��#include���Ă悢
#include"Gun_Custamize_Window.h"

namespace Shooting_HackAndSlash {
	namespace Scene {
		// �P�̃e�X�g�Ƃ����s��������
		class Debug_Scene : public AbstructScene {
			ButtonController buttons;
			
			Gun_Custamize_Window custamize;
		public:
			bool update() override;
			void draw() const override;

			Debug_Scene(ISceneChangeListener& i);
			~Debug_Scene() = default;
		private:
		};
	}
}
