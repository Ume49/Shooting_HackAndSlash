#include "Player.h"

#include"Time.h"
#include"Define.h"
#include"Input.h"
#include"PlayerInfo.h"
#include"Stage_Info.h"

#include<algorithm>
#include"PhotoDisplayer.h"

namespace Shooting_HackAndSlash {
	void Player::init() {
		looks = std::make_unique<PhotoDisplayer>("Resource/Player.png");
		pos.x = Define::Window::PlayArea::Center::Xf;
		pos.y = Define::Window::PlayArea::End::Yf - 10.f;
		collider.OnPositionChanged(pos);
		Time::SetTimer();
	}

	void Player::draw() const {
		looks->display(pos, front);
#ifdef _DEBUG
		collider.draw();
		DrawPixel(static_cast<int>(pos.x), static_cast<int>(pos.y), 0x4169e1);
#endif // _DEBUG
	}

	void Player::update() {
		front = (Input::GetMousePosf() - pos).nomalize();

		Move();
		bomb.check();
		bullet.check(pos);
	}

	void Player::Damage(int damage) {
		PlayerInfo::getInstance().hp -= damage;
		judge_death();
	}

	void Player::Crush() {
		int damage = PlayerInfo::getInstance().max_hp * 2 / 10;

		PlayerInfo::getInstance().hp -= damage;

		judge_death();
	}

	void Player::Move() {
		Vec2 move_direction = Input::GetStick() * Time::DeltaTime() * 120.f;

		pos += move_direction;
		pos.x = std::clamp(pos.x, 0.f, Define::Window::PlayArea::End::Xf);
		pos.y = std::clamp(pos.y, 0.f, Define::Window::PlayArea::End::Yf);
		collider.OnPositionChanged(pos);
	}

	void Player::judge_death() {
		if (PlayerInfo::getInstance().hp <= 0) {
			game_over();
		}
	}

	void Player::game_over() {
		// ゲームクリアフラグはデフォルトでfalseに設定されているので、弄る必要はない
		Time::StopTimer();
		go_result();
	}
}