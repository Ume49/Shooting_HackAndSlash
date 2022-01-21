#include "SE_SharedHandle.h"

#include<DxLib.h>

#include"Abstruct_Shared_Manager.h"

#include"Volume_Info.h"

namespace {
	class Manager : public Shooting_HackAndSlash::Abstruct_Shared_Manager {
	public:
		Manager() = default;
		~Manager() = default;

	protected:
		int load_func(const std::string& path) override;
		void release_func(int handle) override;
	} manager;

	int Manager::load_func(const std::string& path) {
		using namespace Shooting_HackAndSlash;

		// 読み込み
		int handle = LoadSoundMem(path.c_str());

		// 初めての読み込みなので、ハンドルからボリュームを設定
		ChangeVolumeSoundMem(Volume_Info::GetSE(), handle);

		// ボリュームを一括変更するためにVolume_Info側にも登録しておく
		Volume_Info::Resistar_SE_Handle(handle);

		return handle;
	}

	void Manager::release_func(int handle) {
		using namespace Shooting_HackAndSlash;

		// エラーを吐かないようにVolume_Infoから削除
		Volume_Info::Delete_SE_Handle(handle);

		// メモリから消去
		DeleteSoundMem(handle);
	}
}

namespace Shooting_HackAndSlash {
	SE_SharedHandle::SE_SharedHandle(const std::string& p) :
		Abstruct_SharedHandle(p, ::manager) {
	}
}