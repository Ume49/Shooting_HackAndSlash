#pragma once

#include "AbstructScene.h"
#include"ButtonController.h"

#include<string>
#include<vector>

#include"Photo_SharedHandle.h"
#include"BackGround_BigStar.h"

namespace Shooting_HackAndSlash {
	namespace Scene {
		class Title :public AbstructScene {
		private:
			Photo_SharedHandle title_text;
			ButtonController buttons;

			std::vector<BackGround_Object::BigStar> stars;

			bool keep_game;
		public:
			Title(ISceneChangeListener& s);
			~Title() = default;
			void draw() const override;
			bool update() override;
		};
	}
}