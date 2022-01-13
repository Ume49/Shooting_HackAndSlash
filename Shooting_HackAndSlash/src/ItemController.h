#pragma once
#include"ISpawnCallListener.h"

#include<memory>
#include<list>

#include"AbstructItem.h"
#include"ItemSpawnFunc_Table.h"

namespace Shooting_HackAndSlash {
	class Player;
	class ItemController{
		using Pointer = std::unique_ptr<AbstructItem>;
		using List = std::list<Pointer>;
	private:
		List item_list;
		Player& player_ref;
		ItemSpawnFunc_Table func_table;
	public:
		void draw() const;
		void update();

		void call_spawn(const Vec2& pos);

		ItemController(Player& p);
		~ItemController() = default;
	};
}
