#pragma once

#include "AbstructScene.h"
#include"ButtonController.h"

#include<string>

namespace Shooting_HackAndSlash {
	namespace Scene {
		class Title :public AbstructScene {
		private:
			std::string title_text;
			ButtonController buttons;

			bool keep_game;

			void init();
		public:
			Title(ISceneChangeListener& s) :AbstructScene(s), title_text("タイトルシーン"), buttons(), keep_game(true) { init(); }
			~Title() = default;
			void draw() const override;
			bool update() override;
		};
	}
}