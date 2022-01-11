#pragma once
#include"eBullet.h"

#include"IPackagedIcon.h"

namespace Shooting_HackAndSlash {
	class IDropListener {
	public:
		IDropListener() = default;
		virtual ~IDropListener() = default;

		// ドロップできた	 : true
		// ドロップできなかった	: false
		virtual bool CheckDrop(IPackagedIcon& icon) = 0;
	};
}