#pragma once

#include"AbstructScene.h"

#include"Gun_Custamize_Window.h"

#include"Photo_SharedHandle.h"
#include"ButtonController.h"

namespace Shooting_HackAndSlash::Scene {
	class GunCustom : public AbstructScene{
		const AbstructScene& back_scene;

		Gun_Custamize_Window custamize_window;
		ButtonController button_controller;

		Photo_SharedHandle back_screen;
	public:
		GunCustom(ISceneChangeListener& s, const AbstructScene& back);
		~GunCustom() = default;

		bool update() override;
		void draw() const;
	};
}
