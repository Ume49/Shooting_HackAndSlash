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

		// �ǂݍ���
		int handle = LoadSoundMem(path.c_str());

		// ���߂Ă̓ǂݍ��݂Ȃ̂ŁA�n���h������{�����[����ݒ�
		ChangeVolumeSoundMem(Volume_Info::GetSE(), handle);

		// �{�����[�����ꊇ�ύX���邽�߂�Volume_Info���ɂ��o�^���Ă���
		Volume_Info::Resistar_SE_Handle(handle);

		return handle;
	}

	void Manager::release_func(int handle) {
		using namespace Shooting_HackAndSlash;

		// �G���[��f���Ȃ��悤��Volume_Info����폜
		Volume_Info::Delete_SE_Handle(handle);

		// �������������
		DeleteSoundMem(handle);
	}
}

namespace Shooting_HackAndSlash {
	SE_SharedHandle::SE_SharedHandle(const std::string& p) :
		Abstruct_SharedHandle(p, ::manager) {
	}
}