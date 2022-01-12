#pragma once

#include"Vector.h"

namespace Shooting_HackAndSlash {
	// ベクトルを回転させる
	// ラジアンを渡す
	Vec2 Vec2_Rotate(const Vec2& target, float angle);

	// 度数法で表現された角度をラジアンに変換する
	float Degree_to_Radian(float angle_deg);
}