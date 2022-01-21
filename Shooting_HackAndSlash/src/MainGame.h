#pragma once

#include "AbstructScene.h"

#include"Player.h"

#include"UIController.h"
#include"BulletController.h"
#include"EnemyController.h"
#include"EnemySpawner.h"
#include"ItemController.h"

#include"Shooting_Star.h"
#include"BGM_Player.h"

namespace Shooting_HackAndSlash::Scene {
	class MainGame : public AbstructScene {
	private:
		Player player;

		UIController ui;
		BulletController bullet_player;
		ItemController item_controller;
		EnemySpawner enemy_spawner;
		EnemyController enemy_controller;

		BackGround_Object::Shooting_Stars star;

		BGM_Player bgm;
	public:
		bool update() override;
		void draw() const override;

		MainGame(ISceneChangeListener& s);
		~MainGame();
	};
}
