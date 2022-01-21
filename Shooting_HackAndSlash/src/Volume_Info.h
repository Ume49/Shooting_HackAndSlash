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

		// ���ʉ��̉��ʂ��ꊇ�ύX
		void ChangeSEVol();
		// BGM�̉��ʂ��ꊇ�ύX
		void ChangeBGMVol();
	public:

		float se_volume, bgm_volume, master_volume;

		// ���ʉ��̃{�����[����ݒ�
		static void SetSE(float value);
		// BGM�̃{�����[����ݒ�
		static void SetBGM(float value);
		// �}�X�^�[�{�����[����ݒ�
		static void SetMaster(float value);

		// ���ʉ��̑傫�����擾
		static int GetSE();
		// BGM�̑傫�����擾
		static int GetBGM();

		// SE�n���h���o�^
		static void Resistar_SE_Handle(int handle);
		// BGM�n���h���o�^
		static void Resistar_BGM_Handle(int handle);

		// SE�n���h������
		static void Delete_SE_Handle(int handle);
		// BGM�n���h������
		static void Delete_BGM_Handle(int handle);
	};
}
