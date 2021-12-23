#pragma once
#include"eBullet.h"

namespace Shooting_HackAndSlash {
		class IDropListener {
	public:
		IDropListener() = default;
		virtual ~IDropListener() = default;

		// ドロップできた	 : true
		// ドロップできなかった	: false
		virtual bool CheckDrop(const eBullet& b) = 0;
	};
}