#pragma once

#include"AbstructScene.h"
#include<string>
#include"ButtonController.h"

#include"Photo_SharedHandle.h"

namespace Shooting_HackAndSlash {
	namespace Scene {
		class Result : public AbstructScene {
		private:
			std::string result_text;
			ButtonController buttons;

			Point result_pos, time_pos, kill_pos;

			bool keep_game;

			// ”wŒi‚É•\Ž¦‚·‚é
			Photo_SharedHandle back_screen;

			const AbstructScene& back_scene;
		public:
			Result(ISceneChangeListener& s, const AbstructScene& back_scene);
			~Result() = default;

			void draw() const override;
			bool update() override;
		};
	}
}