#include "Volume_Info.h"

#include<DxLib.h>

namespace {
	// ボリューム最大値
	constexpr int max_volume = 255;

	// 割合としてのボリュームの初期値
	constexpr float value_init = 1.f;
}

namespace Shooting_HackAndSlash {
	Volume_Info::Volume_Info() :
		bgm_handles(),
		se_handles(),
		se_volume(::value_init),
		bgm_volume(::value_init),
		master_volume(::value_init)
	{
	}

	void Volume_Info::ChangeSEVol() {
		auto& Ref = Volume_Info::getInstance();

		int volume = Volume_Info::GetSE();

		for (auto& w : Ref.se_handles) {
			ChangeVolumeSoundMem(volume, w);
		}
	}
	
	void Volume_Info::ChangeBGMVol() {
		auto& Ref = Volume_Info::getInstance();

		int volume = Volume_Info::GetBGM();

		for (auto& w : Ref.bgm_handles) {
			ChangeVolumeSoundMem(volume, w);
		}
	}

	void Volume_Info::SetSE(float value) {
		auto& Ref = Volume_Info::getInstance();

		Ref.se_volume = value;

		Ref.ChangeSEVol();
	}

	void Volume_Info::SetBGM(float value) {
		auto& Ref = Volume_Info::getInstance();

		Ref.bgm_volume = value;

		Ref.ChangeBGMVol();
	}

	void Volume_Info::SetMaster(float value) {
		auto& Ref = Volume_Info::getInstance();

		Ref.master_volume = value;

		Ref.ChangeSEVol();
		Ref.ChangeBGMVol();
	}

	int Volume_Info::GetSE() {
		auto& Ref = Volume_Info::getInstance();

		return static_cast<int>(::max_volume * Ref.se_volume * Ref.master_volume);
	}

	int Volume_Info::GetBGM() {
		auto& Ref = Volume_Info::getInstance();

		return static_cast<int>(::max_volume * Ref.bgm_volume * Ref.master_volume);
	}

	void Volume_Info::Resistar_SE_Handle(int handle) {
		Volume_Info::getInstance().se_handles.push_back(handle);
	}

	void Volume_Info::Resistar_BGM_Handle(int handle) {
		Volume_Info::getInstance().bgm_handles.push_back(handle);
	}

	void Volume_Info::Delete_SE_Handle(int handle) {
		Volume_Info::getInstance().se_handles.remove(handle);
	}

	void Volume_Info::Delete_BGM_Handle(int handle) {
		Volume_Info::getInstance().bgm_handles.remove(handle);
	}
}