#pragma once

namespace Shooting_HackAndSlash {
	// �e�̎��
	enum class eBullet : int {
		Null,			// �����Ȃ��B�I�[�ɗ��p�����
		ST,				// �^��������Ԓe
		V,				// ��ɕʂ��V���ɔ�Ԓe
		Star,			// �܂ɕʂ�Đ��^�ɔ�Ԓe
		Refrect,		// ��ʒ[�Ŕ��˂���e
		RightCurve,		// �E�ɋȂ����Ă����e
		LeftCurve 		// ���ɋȂ����Ă����e		
	};

	// �e�������_���Ɏ擾����
	eBullet Random_Bullet();
}