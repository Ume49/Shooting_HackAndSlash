#pragma once

#include<string>
#include"Abstruct_Shared_Manager.h"

namespace Shooting_HackAndSlash {
	// リソースが共有可能なハンドル
	class Abstruct_SharedHandle {
	protected:
		int handle;
		std::string release_key;
		Abstruct_Shared_Manager& manager;
	public:
		operator int() const noexcept;

		Abstruct_SharedHandle(const std::string& s, Abstruct_Shared_Manager& m);
		// これを利用する際は、handle, release_keyを設定してください
		Abstruct_SharedHandle(Abstruct_Shared_Manager& m);

		// コピーコンストラクタ
		Abstruct_SharedHandle(const Abstruct_SharedHandle& s);
		Abstruct_SharedHandle& operator=(const Abstruct_SharedHandle& s) = delete;

		virtual ~Abstruct_SharedHandle();
	};
}
