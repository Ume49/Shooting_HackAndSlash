#pragma once

#include"Vector.h"
#include"Color.h"

namespace Shooting_HackAndSlash::BackGround_Object {
	// タイトル画面で使用する 点滅する星
	class BigStar {
		Vec2 position;
		float count;
		Color color;

		enum class State {
			ON,		// 明るい
			OFF		// 暗い
		} state;
	public:
		 BigStar();
		 BigStar(const Vec2& pos, const Color& c, float deray = 0.f);
		~BigStar() = default;

		// 更新処理 毎フレーム1回だけ呼び出す
		void update();
		// 星を描画する
		void draw() const;
	};
}
