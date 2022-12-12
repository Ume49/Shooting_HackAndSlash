#pragma once

#include"Vector.h"
#include"IOnPositionChangedListener.h"

namespace Shooting_HackAndSlash {
	// 円形の当たり判定
	class CircleCollider : public IOnPositionChangedListener {
	private:
		Vec2  pos;		// 中心座標
		float radius;	// 半径
	public:
		void OnPositionChanged(const Vec2& p) override { pos = p; }

		// デバッグ用
		void draw() const;

		/// <summary>
		/// 衝突判定
		/// </summary>
		/// <param name="target">衝突を判定したい相手</param>
		/// <returns>衝突しているならtrue</returns>
		bool isColide(const CircleCollider& target);
	public:
		CircleCollider() : pos(), radius() {}
		CircleCollider(Vec2& p, float r) : pos(p), radius(r) {}
	};
}
