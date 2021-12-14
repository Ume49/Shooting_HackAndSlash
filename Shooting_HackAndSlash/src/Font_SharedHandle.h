#pragma once

#include"Abstruct_Shared_Handle.h"

namespace Shooting_HackAndSlash {
	// �t�H���g�̋��L�n���h��
	struct Font_SharedHandle : public Abstruct_SharedHandle{
		// �t�H���g�T�C�Y���擾����(�����̍����ɋߎ�����炵��)
		int fontsize() const;

		Font_SharedHandle(const std::string& DX_fontfile_path);
		Font_SharedHandle(const std::string& FontName, int Size, int Thick, int FontType);
		~Font_SharedHandle() = default;
	};
}
