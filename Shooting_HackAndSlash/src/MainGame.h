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

		UIController		ui;					// MainGameシーンで表示するUIを管理するクラス
		BulletController	bullet_player;		// 弾を管理するクラス
		ItemController		item_controller;	// アイテムを管理するクラス
		EnemySpawner		enemy_spawner;		// エネミーを生成するためのクラス
		EnemyController		enemy_controller;	// エネミーをまとめて管理するクラス

		BackGround_Object::Shooting_Stars star;

		BGM_Player bgm;
	public:
		bool update() override;
		void draw() const override;

		MainGame(ISceneChangeListener& s);
		~MainGame();
	};
}
