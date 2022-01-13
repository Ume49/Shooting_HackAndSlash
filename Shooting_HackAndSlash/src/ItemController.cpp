#include "ItemController.h"
#include"Random.h"
#include<cassert>
#include<algorithm>
#include"Player.h"

#include"Item_Cure.h"
#include"eBullet.h"
#include"Item_Bullet.h"

namespace {
	constexpr float Spanw_Rate = 0.7f;

	// 乱数の上限値
	constexpr int random_max = 99;

	// 乱数の下限値
	constexpr int random_min = 0;

	// 回復アイテムの出現率
	constexpr float cure_spawn_rate = 0.30f;

	// 弾アイテムの出現率
	constexpr float bullet_spawn_rate = 0.3f;

	// 銃アイテムの出現率
	constexpr float gun_spawn_rate = 0.05f;
}

namespace Shooting_HackAndSlash {
	ItemController::ItemController(Player& p) :
		item_list(),
		player_ref(p),
		func_table()
	{
		func_table.reserve(4U);

		{	// 各種境界値を計算する
			// 無名名前空間の確率を境界値向けのint型に変換する
			auto convert = [](float rate) {return static_cast<int>(rate * 100.f); };

			// 何も発生しない場合
			int void_rate = 100 - convert(::cure_spawn_rate + ::bullet_spawn_rate + ::gun_spawn_rate) - 1;

			// 回復アイテムを生成する場合
			int cure_rate = void_rate + convert(::cure_spawn_rate);

			// 弾アイテムを生成する場合
			int bullet_rate = cure_rate + convert(::bullet_spawn_rate);

			// 銃アイテムを生成する場合
			int gun_rate = bullet_rate + convert(::gun_spawn_rate);

			{	// 登録
#define Arg const Vec2& pos
				// 何も発生させない
				func_table.add_unsort([&](Arg) {/* 何もしない */}, void_rate);
				// 回復アイテム
				func_table.add_unsort([&](Arg) { item_list.push_back(std::make_unique<Item::Cure>(pos, player_ref)); }, cure_rate);
				// 弾アイテム
				func_table.add_unsort([&](Arg) { item_list.push_back(std::make_unique<Item::Bullet>(Random_Bullet(), pos, player_ref)); }, bullet_rate);
				// 銃アイテム
				func_table.add_unsort([&](Arg) {/* 銃を追加する処理 */}, gun_rate);

				// 最後にソート要求
				func_table.sort();
#undef Arg
			}
		}
	}

	void ItemController::update() {
		for (auto& w : item_list) {
			w->update();
		}

		// 死亡しているアイテムは消去
		item_list.remove_if([](std::unique_ptr<AbstructItem>& w) { return w->is_dead; });
	}

	void ItemController::draw() const {
		for (auto& w : item_list) {
			w->draw();
		}
	}

	void ItemController::call_spawn(const Vec2& p) {
		// ランダムな結果を出す

		// 乱数を取得
		int rand = Random::Range(::random_min, ::random_max);

		// アイテム生成関数を実行
		auto& func = func_table.at(rand);

		func(p);
	}
}