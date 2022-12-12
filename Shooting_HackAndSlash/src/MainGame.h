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

		UIController		ui;					// MainGame�V�[���ŕ\������UI���Ǘ�����N���X
		BulletController	bullet_player;		// �e���Ǘ�����N���X
		ItemController		item_controller;	// �A�C�e�����Ǘ�����N���X
		EnemySpawner		enemy_spawner;		// �G�l�~�[�𐶐����邽�߂̃N���X
		EnemyController		enemy_controller;	// �G�l�~�[���܂Ƃ߂ĊǗ�����N���X

		BackGround_Object::Shooting_Stars star;

		BGM_Player bgm;
	public:
		bool update() override;
		void draw() const override;

		MainGame(ISceneChangeListener& s);
		~MainGame();
	};
}
