#pragma once
#include"AbstructScene.h"
#include"ButtonController.h"

// ここから先自由に#includeしてよい
#include"Gun_Custamize_Window.h"

namespace Shooting_HackAndSlash {
	namespace Scene {
		// 単体テストとかを行う実験場
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
