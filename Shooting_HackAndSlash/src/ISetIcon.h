#pragma once
#include"eBullet.h"

namespace Shooting_HackAndSlash {
	class ISetIcon {
	public:
		ISetIcon() = default;
		virtual ~ISetIcon() = default;

		// �A�C�R�����Z�b�g����
		virtual void SetIcon(const eBullet& bullet_kind) = 0;
	};
}