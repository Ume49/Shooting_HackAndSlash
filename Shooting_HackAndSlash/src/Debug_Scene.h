#pragma once
#include"AbstructScene.h"
#include"ButtonController.h"

// ここから先自由に#includeしてよい
#include"Gun_Custamize_Window.h"
#include"BackGround_BigStar.h"
#include<vector>

namespace Shooting_HackAndSlash {
	namespace Scene {
		// 単体テストとかを行う実験場
		class Debug_Scene : public AbstructScene {
			ButtonController buttons;

			Gun_Custamize_Window custamize;

			std::vector<BackGround_Object::BigStar> star;
		public:
			bool update() override;
			void draw() const override;

			Debug_Scene(ISceneChangeListener& i);
			~Debug_Scene() = default;
		private:
		};
	}
}
