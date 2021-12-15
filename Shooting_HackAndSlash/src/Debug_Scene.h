#pragma once
#include"AbstructScene.h"
#include"ButtonController.h"

#include"VolumeController.h"

#include"Fade.h"

#include"BackPack.h"

namespace Shooting_HackAndSlash {
	namespace Scene {
		// 単体テストとかを行う実験場
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
