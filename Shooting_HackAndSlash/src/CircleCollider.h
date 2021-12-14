#pragma once

#include"Vector.h"
#include"IOnPositionChangedListener.h"

namespace Shooting_HackAndSlash {
	class CircleCollider : public Interface::IOnPositionChangedListener {
	private:
		Vec2 pos;
		float radius;
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
