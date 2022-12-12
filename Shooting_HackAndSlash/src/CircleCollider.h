#pragma once

#include"Vector.h"
#include"IOnPositionChangedListener.h"

namespace Shooting_HackAndSlash {
	// �~�`�̓����蔻��
	class CircleCollider : public IOnPositionChangedListener {
	private:
		Vec2  pos;		// ���S���W
		float radius;	// ���a
	public:
		void OnPositionChanged(const Vec2& p) override { pos = p; }

		// �f�o�b�O�p
		void draw() const;

		/// <summary>
		/// �Փ˔���
		/// </summary>
		/// <param name="target">�Փ˂𔻒肵��������</param>
		/// <returns>�Փ˂��Ă���Ȃ�true</returns>
		bool isColide(const CircleCollider& target);
	public:
		CircleCollider() : pos(), radius() {}
		CircleCollider(Vec2& p, float r) : pos(p), radius(r) {}
	};
}
