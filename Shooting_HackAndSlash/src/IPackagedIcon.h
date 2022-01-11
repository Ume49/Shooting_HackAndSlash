#pragma once

#include"eBullet.h"

namespace Shooting_HackAndSlash {
	class IPackagedIcon {
	public:
		IPackagedIcon() = default;
		virtual ~IPackagedIcon() = default;

		virtual eBullet& get_Bullet() = 0;
		virtual size_t get_index() = 0;
	};
}
