#include "Stage_Info.h"

namespace {
	// 要求討伐数の初期値
	constexpr int INIT = 30;
	// 要求討伐数の上昇量
	constexpr int UP = 30;
}

namespace Shooting_HackAndSlash {
	Stage_Info::Stage_Info() :
		stage_num(0),
		enemy_kill_count(0),
		kill_clear_count(0),
		clear(false),
		stageclear_func(){
	}

	void Stage_Info::initialize() {
		auto& info = Stage_Info::getInstance();

		info.stage_num = 0;
		info.enemy_kill_count = 0;
		info.kill_clear_count = 0;
		info.clear = false;
	}

	bool Stage_Info::Is_GameClear() {
		return Stage_Info::getInstance().clear;
	}

	bool Stage_Info::Is_StageClear() {
		auto& info = Stage_Info::getInstance();

		return info.enemy_kill_count >= info.kill_clear_count;
	}

	void Stage_Info::Call_Enemy_Kill() {
		auto& info = Stage_Info::getInstance();

		info.enemy_kill_count++;

		// 討伐しきったのであればステージクリア呼び出し
		if (info.enemy_kill_count >= info.kill_clear_count) {
			info.stageclear_func();
		}
	}

	void Stage_Info::Set_Stage_Next() {
		auto& info = Stage_Info::getInstance();

		info.stage_num++;

		// 要求討伐数を再計算
		info.kill_clear_count = ::INIT + (::UP * (info.stage_num - 1));

		// 討伐数をリセット
		info.enemy_kill_count = 0;
	}

	int Stage_Info::Show_KillCount() {
		return Stage_Info::getInstance().enemy_kill_count;
	}

	int Stage_Info::Show_Remaining() {
		auto& info = Stage_Info::getInstance();
		return info.kill_clear_count - info.enemy_kill_count;
	}

	void Stage_Info::SetStageClearFunc(std::function<void(void)> f) {
		Stage_Info::getInstance().stageclear_func = f;
	}

	int Stage_Info::Show_Stage_Num() {
		return Stage_Info::getInstance().stage_num;
	}
}