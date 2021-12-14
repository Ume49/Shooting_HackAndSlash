#pragma once

#include"Singleton.h"
#include<functional>

namespace Shooting_HackAndSlash {
	class Stage_Info : public Singleton<Stage_Info> {
	private:
		// 現在のステージ番号
		int stage_num;
		// 討伐数
		// 現在エネミーを何体倒したか、という値
		int enemy_kill_count;
		// 要求討伐数
		// 何体倒したらそのステージがクリアになるか、という値
		int kill_clear_count;
		// ゲームをクリアしたかどうか
		bool clear;

		// シーン遷移関数
		std::function<void(void)> stageclear_func;
	public:
		// 値の初期化
		static void initialize();

		// パラメータを次のステージ用にする
		static void Set_Stage_Next();

		// ゲームをクリアしているか
		static bool Is_GameClear();

		// ステージをクリアしているか
		static bool Is_StageClear();

		// エネミー討伐通知
		static void Call_Enemy_Kill();

		// エネミー討伐数を公開
		static int Show_KillCount();

		// 残り討伐数を公開
		static int Show_Remaining();

		// ステージをクリアする処理をセット
		static void SetStageClearFunc(std::function<void(void)>);

		// ステージ番号を公開
		static int Show_Stage_Num();
	private:
		friend Singleton;
		Stage_Info();
		~Stage_Info() = default;
	};
}
