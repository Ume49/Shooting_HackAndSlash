#pragma once

#include"AbstructScene.h"
#include"ButtonController.h"

#include<DxLib.h>

namespace Shooting_HackAndSlash {
	namespace Scene {
		// どのシーンに行くのか選択する、デバッグモード専用シーン
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