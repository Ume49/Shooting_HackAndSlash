#pragma once

#include "AbstructScene.h"
#include"ButtonController.h"

#include<string>

#include"Photo_SharedHandle.h"

namespace Shooting_HackAndSlash {
	namespace Scene {
		class Title :public AbstructScene {
		private:
			Photo_SharedHandle title_text;
			ButtonController buttons;

			bool keep_game;
		public:
			Title(ISceneChangeListener& s);
			~Title() = default;
			void draw() const override;
			bool update() override;
		};
	}
}