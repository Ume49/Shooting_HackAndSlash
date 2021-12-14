#pragma once

#include"Vector.h"

namespace Shooting_HackAndSlash {
	namespace Interface {
		class IOnPositionChangedListener {
		public:
			IOnPositionChangedListener() = default;
			virtual void OnPositionChanged(const Vec2& p) = 0;
			virtual ~IOnPositionChangedListener() = default;
		};
	}
}