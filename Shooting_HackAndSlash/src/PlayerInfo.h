#pragma once

#include"Singleton.h"
#include"SE_Player.h"

namespace Shooting_HackAndSlash {
	class PlayerInfo : public Singleton<PlayerInfo> {
		static constexpr int INIT_HP = 100;
		static constexpr float INIT_SPEED = 0.f;
		static constexpr int INIT_ATK = 1;
		static constexpr int INIT_BOMB = 3;

		SE_Player sound;

	public:
		int hp, max_hp, atk;
		float speed;
		int bomb_count;


		// HPを回復する
		static void Cure(int value);

		// ダメージを与える
		static void Damage(int value);

		// データの初期化
		static void initialize();

		
	private:
		friend Singleton;
		PlayerInfo() :
			hp(100), max_hp(100),
			atk(1),
			speed(0),
			bomb_count(3) ,
			sound("Resource/damage2.mp3")
		{}
		~PlayerInfo() = default;
	};
}