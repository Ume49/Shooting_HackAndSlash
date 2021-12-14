#pragma once

#include"Abstruct_Shared_Handle.h"

namespace Shooting_HackAndSlash {
	// フォントの共有ハンドル
	struct Font_SharedHandle : public Abstruct_SharedHandle{
		// フォントサイズを取得する(文字の高さに近似するらしい)
		int fontsize() const;

		Font_SharedHandle(const std::string& DX_fontfile_path);
		Font_SharedHandle(const std::string& FontName, int Size, int Thick, int FontType);
		~Font_SharedHandle() = default;
	};
}
