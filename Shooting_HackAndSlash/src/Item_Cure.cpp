#include "Item_Cure.h"
#include"Define.h"
#include<DxLib.h>
#include"Player.h"
#include"PlayerInfo.h"
#include"Time.h"

namespace {
	constexpr float collider_radius = 10.f;
	// ‰ñ•œ—Ê
	const int cure_point = 10;
}

namespace PATH = Shooting_HackAndSlash::Define::Path::Photo;

namespace Shooting_HackAndSlash::Item {
	Cure::Cure(const Vec2& p, Player& pl) :
		AbstructItem(PATH::Cristal, pl, p)
	{
		pos = p;
		collider.OnPositionChanged(p);
	}

	void Cure::draw() const {
		// Œ©‚½–Ú‚ð•`‰æ
		display();
	}

	void Cure::OnCollide(Player& p) {
		PlayerInfo::Cure(::cure_point);
	}
}