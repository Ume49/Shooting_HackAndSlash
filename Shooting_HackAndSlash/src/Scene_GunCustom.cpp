#include "Scene_GunCustom.h"

#include"Define.h"

#include"Input.h"

namespace {
	using namespace Shooting_HackAndSlash;
	const Point return_button_pos{ 20, Define::Window::HEIGHT-90 };
}

namespace Shooting_HackAndSlash::Scene {
	GunCustom::GunCustom(ISceneChangeListener& s, const AbstructScene& back) :
		AbstructScene(s),
		custamize_window(),
		back_scene(back),
		back_screen(Define::Path::Photo::BackScreen){
		button_controller.Add([&]() { listener.ScenePop(); }, "Return", ::return_button_pos);
	}

	bool GunCustom::update() {
		// Esc‚ğ‰Ÿ‚µ‚½‚ç‘O‚ÌƒV[ƒ“‚É–ß‚é
		if (Input::GetDown(Inputcode::Esc)) {
			listener.ScenePop();
		}

		button_controller.update();
		custamize_window.update();

		return true;
	}

	void GunCustom::draw() const {
		back_scene.draw();

		DrawGraph(0, 0, back_screen, TRUE);

		button_controller.draw();
		custamize_window.draw();
	}
}