#pragma once

#include"Abstruct_Shared_Handle.h"
#include"Vector.h"

namespace Shooting_HackAndSlash {
	// �Î~�摜�̋��L�n���h��
	struct Photo_SharedHandle : public Abstruct_SharedHandle {
	public:
		// �摜�̃T�C�Y���擾���ĕԂ�
		Point size() const;

		// �L�[�����J����
		const std::string& getkey() const;

		// �摜��o�^���Ȃ�
		Photo_SharedHandle();
		// path : �o�^����摜�̃p�X
		Photo_SharedHandle(const std::string& path);
		~Photo_SharedHandle() = default;
	};
}
