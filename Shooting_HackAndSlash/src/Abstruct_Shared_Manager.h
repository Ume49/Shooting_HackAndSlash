#pragma once

#include<unordered_map>
#include<string>
#include"Singleton.h"

namespace Shooting_HackAndSlash {
	// ���L�n���h���̃I���W�i���̃n���h�����i�[���邽�߂̃}�l�[�W���[
	// �p����œǂݍ��݊֐��Ɖ���֐����`���Ďg��
	class Abstruct_Shared_Manager {
	protected:
		struct Handle {
			int value, reference_count;
		};

		std::unordered_map<std::string, Handle> container;

		// ���\�[�X��ǂݍ��ޏ���
		virtual int load_func(const std::string& path) = 0;
		// ����̃��\�[�X��������鏈��
		virtual void release_func(int handle) = 0;

	public:
		int Load(const std::string& path);
		// �蓮�ŎQ�ƃJ�E���g����	
		// ���i��Load�œ�������������Ă��邪�A�R�s�[�R���X�g���N�^���g�p�����ꍇ�Ɏg��
		void Count_Add(const std::string& key);
		void Release(const std::string& path);

		Abstruct_Shared_Manager();
		virtual ~Abstruct_Shared_Manager() = default;
	};
}
