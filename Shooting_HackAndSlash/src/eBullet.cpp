#include"eBullet.h"

#include"Random.h"

namespace {
	// 開始
	// 0はNullが入っているので
	constexpr int begin = 1;

	// 末尾
	// eBulletの最後のものを入れること
	constexpr int end = static_cast<int>(Shooting_HackAndSlash::eBullet::LeftCurve);
}

namespace Shooting_HackAndSlash {
	eBullet Random_Bullet() {
		return static_cast<eBullet>(Random::Range(::begin, ::end));
	}
}