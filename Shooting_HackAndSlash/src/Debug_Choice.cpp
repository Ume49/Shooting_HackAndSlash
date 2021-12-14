#include "Debug_Choice.h"
#include"Input.h"
#include"Define.h"

namespace Shooting_HackAndSlash::Scene {
	Debug_Choice::Debug_Choice(ISceneChangeListener& i) : 
		AbstructScene(i),
		is_quit(true),
		buttons() {
		// ƒ{ƒ^ƒ“‚ð“o˜^
		buttons.Add([&]() { is_quit = false; }, "Quit", Point{ 600,900 });
		buttons.Add([&]() { listener.SceneChange(eScene::Title, true); }, "Title", Point{ 100,100 });
		buttons.Add([&]() {listener.SceneChange(eScene::Debug); }, "DebugScene", Point{ 100,200 });
		buttons.Add([&]() {listener.SceneChange(eScene::Menu); }, "Menu", Point{ 100,300 });
	}

	bool Debug_Choice::update() {
		buttons.update();

		return is_quit;
	}

	void Debug_Choice::draw() const {
		DrawString(10, 10, "Here is loaded when just Debug.\nChoice a Scene.", Palette::White);
		DrawFormatString(400, 10, Palette::White, "Mouse(%d, %d)", Input::GetMousePos().x, Input::GetMousePos().y);
		buttons.draw();
	}
}