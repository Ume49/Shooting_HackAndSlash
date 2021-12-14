#pragma once

#include"Vector.h"

namespace Shooting_HackAndSlash {
	// �O���t�B�J���ɕ\�����邽�߂̃C���^�[�t�F�[�X
	class IDisplayer {
	public:
		IDisplayer() = default;
		virtual ~IDisplayer() = default;

		// �\������
		// position : �������W
		virtual void display(const Vec2& pos_center, const Vec2& direction) const = 0;
	};
}
