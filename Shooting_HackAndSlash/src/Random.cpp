#include "Random.h"
#include<cassert>

namespace Shooting_HackAndSlash {
	bool Random::Question(int numerator, int denominator) {
		assert(numerator <= denominator);

		// 引数の型を合わせる
		uint32_t u32_n = static_cast<uint32_t>(numerator);
		uint32_t u32_d = static_cast<uint32_t>(denominator);

		// 乱数を取得
		uint32_t rand = Random::getInstance().random_machine();

		// 乱数を加工
		uint32_t rand_resized = rand % u32_d;

		return rand_resized <= u32_n;
	}

	bool Random::Question(float true_rate) {
		// 比較用の数を取得
		uint32_t border = static_cast<uint32_t>(true_rate * Random::getInstance().random_machine.max());

		// 乱数を取得
		uint32_t rand = Random::getInstance().random_machine();

		return (rand <= border);
	}

	int Random::Range(int min, int max) {
		assert(min < max);

		// 乱数の加工用にmin~maxの長さを計算
		// ついでに型変換
		uint32_t range = static_cast<uint32_t>(max - min + 1);

		// 乱数を取得
		uint32_t rand = Random::getInstance().random_machine();

		// 乱数を加工
		// 0~(max-min)までの数字を返して欲しい
		int rand_reshaped = static_cast<int>(rand % range);

		// 下駄を履かせてリターン
		return rand_reshaped + min;
	}
}