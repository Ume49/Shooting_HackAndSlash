#pragma once
#include<list>
#include<memory>
#include"AbstructItem.h"

namespace Shooting_HackAndSlash {
	class ItemSpawner{
	public:
		using _List = std::list<std::unique_ptr<AbstructItem>>;

		void Spawn();

		ItemSpawner();
		~ItemSpawner()=default;
	};
}
