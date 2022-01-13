#pragma once

#include<vector>
#include<functional>
#include<list>
#include<memory>

#include"AbstructItem.h"

namespace Shooting_HackAndSlash {
	// 0~99までの数字を与えると対応した関数オブジェクトを返してくれるクラス
	// 確率対応表みたいに使える
	class ItemSpawnFunc_Table {
		using Func = std::function<void(const Vec2& pos)>;

		struct Set {
			Func func;
			int border;
		};

		std::vector<Set> container;

	public:
		ItemSpawnFunc_Table();
		~ItemSpawnFunc_Table() = default;

		// 0~99までの値を与えると対応した関数を返す
		Func& at(int num);

		// 項目を追加
		// ソートしないので、全ての追加が終わった時はsort()を呼び出すこと
		void add_unsort(Func, int border);

		// 内部コンテナをソート
		// add_unsortを全て行った後に行うべき
		void sort();

		// 内部コンテナの大きさを明示的に予約する
		void reserve(size_t size);
	};
}
