#pragma once
#include"eBullet.h"

namespace Shooting_HackAndSlash {
	class IBackListener;
	class ISetIcon {
	public:
		ISetIcon() = default;
		virtual ~ISetIcon() = default;

		// �A�C�R�����Z�b�g����
		// return_index : ���̓Y����
		virtual void SetIcon(const eBullet& bullet_kind, IBackListener& back, size_t return_index) = 0;
	};
}