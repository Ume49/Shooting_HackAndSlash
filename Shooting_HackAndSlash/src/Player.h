#pragma once

#include"Vector"
#include"AbstructGameObject.h"

#include"CircleCollider.h"

#include"Bomb_Launcher.h"
#include"Bullet_Lancher.h"

#include"BulletController_Player.h"

#include<memory>
#include<functional>
#include"IDisplayer.h"

namespace Shooting_HackAndSlash {
	class Player : public AbstructGameObject {
		static constexpr float radius = 12.f;
	private:
		void Move();
		// ゲームオーバー処理
		void game_over();
		void init();
		// 死んだか判定
		void judge_death();
	public:
		/// <summary>
		/// ダメージ関数
		/// </summary>
		/// <param name="damage">与えるダメージ</param>
		/// <returns>ダメージを与えた後HPが0になるならfalse</returns>
		void Damage(int damage);

		// エネミー本体と接触した時の処理
		void Crush();

		void update() override;
		void draw() const override;

		const Bullet_Lancher& show_bulletlancher() const { return bullet; }
		const Vec2& show_position() const { return pos; }
	public:
		CircleCollider collider;
	private:
		// 見た目を表示する機能
		std::unique_ptr<IDisplayer> looks;

		std::function<void(void)> go_result;

		Bomb_Launcher bomb;
		Bullet_Lancher bullet;

		// 正面方向
		Vec2 front;
	public:
		Player(BulletController_Player& b, std::function<void()> func_go_result) :
			looks(),
			collider(pos, radius),
			bomb(),
			bullet(b),
			go_result(func_go_result),
			front(0.f,0.f){
			init();
		}
	};
}
