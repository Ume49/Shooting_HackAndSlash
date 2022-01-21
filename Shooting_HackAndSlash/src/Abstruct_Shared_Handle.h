#pragma once

#include<string>
#include"Abstruct_Shared_Manager.h"

namespace Shooting_HackAndSlash {
	// ���\�[�X�����L�\�ȃn���h��
	class Abstruct_SharedHandle {
	protected:
		int handle;
		std::string release_key;
		Abstruct_Shared_Manager& manager;
	public:
		operator int() const noexcept;

		Abstruct_SharedHandle(const std::string& s, Abstruct_Shared_Manager& m);
		// ����𗘗p����ۂ́Ahandle, release_key��ݒ肵�Ă�������
		Abstruct_SharedHandle(Abstruct_Shared_Manager& m);

		// �R�s�[�R���X�g���N�^
		Abstruct_SharedHandle(const Abstruct_SharedHandle& s);
		Abstruct_SharedHandle& operator=(const Abstruct_SharedHandle& s) = delete;

		virtual ~Abstruct_SharedHandle();
	};
}
