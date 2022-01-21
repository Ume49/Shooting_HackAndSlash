#pragma once

#include"Singleton.h"
#include<string>
#include<list>

namespace Shooting_HackAndSlash {
	class Volume_Info : public Singleton<Volume_Info> {
		friend Singleton;
		Volume_Info();
		~Volume_Info() = default;

		std::list<int> bgm_handles, se_handles;

		// 効果音の音量を一括変更
		void ChangeSEVol();
		// BGMの音量を一括変更
		void ChangeBGMVol();
	public:

		float se_volume, bgm_volume, master_volume;

		// 効果音のボリュームを設定
		static void SetSE(float value);
		// BGMのボリュームを設定
		static void SetBGM(float value);
		// マスターボリュームを設定
		static void SetMaster(float value);

		// 効果音の大きさを取得
		static int GetSE();
		// BGMの大きさを取得
		static int GetBGM();

		// SEハンドル登録
		static void Resistar_SE_Handle(int handle);
		// BGMハンドル登録
		static void Resistar_BGM_Handle(int handle);

		// SEハンドル消去
		static void Delete_SE_Handle(int handle);
		// BGMハンドル消去
		static void Delete_BGM_Handle(int handle);
	};
}
