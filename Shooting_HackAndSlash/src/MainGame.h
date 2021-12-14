#pragma once

#include "AbstructScene.h"
#include"Player.h"
#include"UIController.h"
#include"BulletController_Player.h"
#include"EnemyController.h"
#include"EnemySpawner.h"
#include"CursorDrawer.h"
#include"ItemController.h"

namespace Shooting_HackAndSlash {
	namespace Scene {
		class MainGame : public AbstructScene {
		private:
			Player player;
			UIController ui;
			BulletController_Player bullet_player; 
			ItemController item_controller;
			EnemySpawner enemy_spawner;
			EnemyController enemy_controller;
		public:
			bool update() override;
			void draw() const override;

			MainGame(ISceneChangeListener& s);
			~MainGame() = default;
		};
	}
}