#pragma once

namespace Shooting_HackAndSlash {
	// �e�̎��
	// ST : ���i����
	// Single , Double , Triple : ���ł�����A���̒e�ۂ𐶐�����̂�
	enum class eBullet : int {
		Null,
		ST,
		V,
		Star,
		Refrect,
		RightCurve,
		LeftCurve
	};

	// �e�������_���Ɏ擾����
	eBullet Random_Bullet();
}