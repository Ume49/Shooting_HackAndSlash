#pragma once

#include<unordered_map>
#include<string>
#include"Singleton.h"

namespace Shooting_HackAndSlash {
	// 共有ハンドルのオリジナルのハンドルを格納するためのマネージャー
	// 継承先で読み込み関数と解放関数を定義して使う
	class Abstruct_Shared_Manager {
	protected:
		struct Handle {
			int value, reference_count;
		};

		std::unordered_map<std::string, Handle> container;

		// リソースを読み込む処理
		virtual int load_func(const std::string& path) = 0;
		// 特定のリソースを解放する処理
		virtual void release_func(int handle) = 0;

	public:
		int Load(const std::string& path);
		// 手動で参照カウント増加	
		// 普段はLoadで同じ処理がされているが、コピーコンストラクタを使用した場合に使う
		void Count_Add(const std::string& key);
		void Release(const std::string& path);

		Abstruct_Shared_Manager();
		virtual ~Abstruct_Shared_Manager() = default;
	};
}
