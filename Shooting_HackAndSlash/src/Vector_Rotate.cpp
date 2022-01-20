#include"Vec2_Rotate.h"

#include<numbers>
#include<cmath>

namespace {
	// 度数をラジアンに変換するための係数
	constexpr auto deg_to_rad = std::numbers::pi_v < float > / 180.f;
}

namespace Shooting_HackAndSlash {
	// ベクトルを回転させる
	// ラジアンを渡す
	Vec2 Vec2_Rotate(const Vec2& target, float angle) {
		auto sin = std::sinf(angle);
		auto cos = std::cosf(angle);

		return Vec2(target.x * cos - target.y * sin, target.x * sin + target.y * cos);
	}

	// 度数法で表現された角度をラジアンに変換する
	float Degree_to_Radian(float angle_deg) {
		return angle_deg * ::deg_to_rad;
	}
}	