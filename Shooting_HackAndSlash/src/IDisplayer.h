#pragma once

#include"Vector.h"

namespace Shooting_HackAndSlash {
	// グラフィカルに表示するためのインターフェース
	class IDisplayer {
	public:
		IDisplayer() = default;
		virtual ~IDisplayer() = default;

		// 表示する
		// position : 中央座標
		virtual void display(const Vec2& pos_center, const Vec2& direction) const = 0;
	};
}
