#include "Volume_Set_Scene.h"

#include"Vector.h"

#include"Input.h"

namespace {
	const Point volume_pos{70,350};
	const Point button_pos{ 73,353 };
}

namespace Shooting_HackAndSlash::Scene {
	Volume_Set::Volume_Set(ISceneChangeListener& s, const AbstructScene& b) :
		AbstructScene(s),
		back_scene(b),
		volume_controller(::volume_pos),
		button_controller(){
		// ‰æ–Ê‚ğ’Eo‚·‚éƒ{ƒ^ƒ“‚Ì’Ç‰Á
		button_controller.Add([&]() { listener.ScenePop(); }, "Return", ::button_pos);
	}

	bool Volume_Set::update() {
		volume_controller.update();
		button_controller.update();

		if (Input::GetDown(Inputcode::Esc)) {
			listener.ScenePop();
		}


		return true;
	}

	void Volume_Set::draw() const {
		back_scene.draw();
		volume_controller.draw();
		button_controller.draw();
	}
}