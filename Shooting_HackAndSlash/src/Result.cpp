#include "Result.h"

#include"Stage_Info.h"
#include"Time.h"
#include"Define.h"

namespace {
	constexpr char CLEAR[] = "CLEAR!!";
	constexpr char FAILED[] = "FAILED...";
	constexpr uint32_t COLOR = 0xffffff;
}

namespace Shooting_HackAndSlash::Scene {
	Result::Result(ISceneChangeListener& s, const AbstructScene& back_scene) :
		AbstructScene(s),
		back_scene(back_scene),
		result_text(),
		buttons(),
		result_pos(),
		time_pos(),
		kill_pos(),
		keep_game(true),
		back_screen(Define::Path::Photo::BackScreen)
	{
		result_text = Stage_Info::Is_GameClear() ? CLEAR : FAILED;
		buttons.Add([&]() {listener.SceneChange(eScene::Title, true); }, "Return to Title", Point{ 45,920 });
		buttons.Add([&]() {keep_game = false; }, "Quit Game", Point{ 623, 920 });
		result_pos = Point(100, 100);
		time_pos = Point(100, 200);
		kill_pos = Point(100, 300);
	}

	bool Result::update() {
		buttons.update();
		return keep_game;
	}

	void Result::draw() const {
		// îwå„Ç…ëOÇÃÉVÅ[ÉìÇï`âÊ
		back_scene.draw();

		// ÉtÉBÉãÉÄÇï`âÊ
		DrawGraph(0, 0, back_screen, TRUE);

		DrawFormatString(result_pos.x, result_pos.y, COLOR, result_text.c_str());
		DrawFormatString(time_pos.x, time_pos.y, COLOR, "Time %d:%d", Time::GetTimer_minute(), Time::GetTimer_seconds());
		DrawFormatString(kill_pos.x, kill_pos.y, COLOR, "kill : %d", Stage_Info::Show_KillCount());
		buttons.draw();
	}
}