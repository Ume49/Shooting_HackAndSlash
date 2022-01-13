#pragma once
#include"AbstructItem.h"
#include"ISpawnCallListener.h"
#include<memory>
#include<list>

namespace Shooting_HackAndSlash {
	class Player;
	class ItemController{
		using Pointer = std::unique_ptr<AbstructItem>;
	private:
		std::list<Pointer> item_list;
		Player& player_ref;
	public:
		void draw() const;
		void update();

		void call_spawn(const Vec2& pos);

		ItemController(Player& p);
		~ItemController() = default;
	};
}
