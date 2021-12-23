#pragma once

namespace Shooting_HackAndSlash {
	class IBackListener {
	public:
		IBackListener() = default;
		virtual ~IBackListener() = default;

		// 戻る
		virtual void Back(size_t index, const eBullet& bullet) = 0;
	};
}