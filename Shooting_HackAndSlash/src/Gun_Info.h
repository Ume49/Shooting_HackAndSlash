#pragma once
#include"Singleton.h"
#include<vector>
#include"Gun.h"

namespace Shooting_HackAndSlash {
	class Gun_Info : public Singleton<Gun_Info> {
		friend Singleton;
		Gun_Info();
		~Gun_Info() = default;

		// 現在所有している銃
		std::vector<Gun_Custamize::Gun> guns;
	public:
		// 初期化
		static void initialize();

		// 要素へのアクセス
		static Gun_Custamize::Gun& at(size_t index);

		// 銃を追加する
		static void Add(size_t magazine_length);
	};
}
