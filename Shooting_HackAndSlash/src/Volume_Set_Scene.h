#pragma once

#include"AbstructScene.h"

#include"VolumeController.h"
#include"ButtonController.h"

namespace Shooting_HackAndSlash::Scene {
	class Volume_Set : public AbstructScene {
		const AbstructScene& back_scene;

		VolumeController volume_controller;
		ButtonController button_controller;
	public:
		Volume_Set(ISceneChangeListener& s, const AbstructScene& back_scene);
		~Volume_Set() = default;

		bool update() override;
		void draw() const override;
	};
}
