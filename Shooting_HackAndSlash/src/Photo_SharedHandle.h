#pragma once

#include"Abstruct_Shared_Handle.h"
#include"Vector.h"

namespace Shooting_HackAndSlash {
	// 静止画像の共有ハンドル
	struct Photo_SharedHandle : public Abstruct_SharedHandle {
	public:
		// 画像のサイズを取得して返す
		Point size() const;

		// キーを公開する
		const std::string& getkey() const;

		// 画像を登録しない
		Photo_SharedHandle();
		// path : 登録する画像のパス
		Photo_SharedHandle(const std::string& path);
		~Photo_SharedHandle() = default;
	};
}
