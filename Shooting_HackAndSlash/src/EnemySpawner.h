#pragma once

#include"EnemyController.h"
#include"eEnemy.h"

#include<vector>

namespace Shooting_HackAndSlash {
	class Player;
	class EnemySpawner {
	public:
		struct Enemy_Info {
			eEnemy kind;
			Vec2 pos;
		};

	private:
		const Player& player;
		EnemyController& controller;

		std::vector<std::vector<Enemy_Info>> party_list;

		float spawn_interval;
		float spawn_count;
	public:
		void update();

		EnemySpawner(const Player& p, EnemyController& e);
		~EnemySpawner() = default;
	};
}
