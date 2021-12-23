#pragma once
#include"eBullet.h"

namespace Shooting_HackAndSlash {
	class IBackListener;
	class ISetIcon {
	public:
		ISetIcon() = default;
		virtual ~ISetIcon() = default;

		// アイコンをセットする
		// return_index : 元の添え字
		virtual void SetIcon(const eBullet& bullet_kind, IBackListener& back, size_t return_index) = 0;
	};
}