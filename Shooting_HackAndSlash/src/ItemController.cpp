#include "ItemController.h"
#include"Random.h"
#include<cassert>
#include<algorithm>
#include"Player.h"

#include"Item_Cure.h"

namespace {
	constexpr float Spanw_Rate = 0.7f;

	// 乱数の上限値
	constexpr int random_max = 100;
}

namespace Shooting_HackAndSlash {
	ItemController::ItemController(Player& p) :
		item_list(),
		player_ref(p) {
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
		assert(Spanw_Rate <= 1.f);

		if (Random::Question(Spanw_Rate)) {
			// アイテムをランダムに選ぶ
			
			// ランダムな数列を生成
			int rand = Random::Range(0, ::random_max);

			

			{	// アイテム生成
				item_list.push_back(std::make_unique<Item::Cure>(p, player_ref));
			}
		}
	}
}