#include "ItemSpawnFunc_Table.h"

#include<cassert>
#include<algorithm>

namespace {
	// 数列の最低値
	constexpr int index_min = 0;

	// 数列の最大値
	constexpr int index_max = 99;
}

namespace Shooting_HackAndSlash {
	ItemSpawnFunc_Table::ItemSpawnFunc_Table() :
		container()
	{
	}

	void ItemSpawnFunc_Table::reserve(size_t t) {
		container.reserve(t);
	}

	ItemSpawnFunc_Table::Func& ItemSpawnFunc_Table::at(int num) {
		// 範囲外の数列を弾く
		assert(num >= index_min && num <= ::index_max && "確率テーブルに与えられた数値が範囲外です");

		// 境界値がnumに隣接していてnumより大きい要素を検索
		auto itr = std::find_if(container.begin(), container.end(), [&](Set& s) {return num < s.border; });

		// どの境界値よりもnumが大きい場合は末尾+1を吐いてしまうので、デクリメントして末尾にしておく
		if (itr == container.end()) itr--;

		// 見つけた要素の関数オブジェクトを公開して終了
		return itr->func;
	}

	void ItemSpawnFunc_Table::add_unsort(Func f, int border) {
		container.push_back(Set{ f, border });
	}

	// 昇順にソート
	void ItemSpawnFunc_Table::sort() {
		std::sort(container.begin(), container.end(), [](Set& a, Set& b) {return a.border < b.border; });
	}
}