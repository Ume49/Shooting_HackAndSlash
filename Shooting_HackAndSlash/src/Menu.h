#pragma once

#include "AbstructScene.h"
#include"ButtonController.h"
#include"Photo_SharedHandle.h"

namespace Shooting_HackAndSlash {
	namespace Scene {
		class Menu : public AbstructScene {
		private:
			ButtonController buttons;

			bool keep_game;
			Photo_SharedHandle back_screen;

			const AbstructScene& back_scene;

		public:
			Menu(ISceneChangeListener& s, const AbstructScene& back);
			~Menu();

			bool update() override;
			void draw() const override;
		};
	}
}