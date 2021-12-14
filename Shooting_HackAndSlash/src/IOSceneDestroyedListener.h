#pragma once
#include"eScene.h"

namespace Shooting_HackAndSlash {
	class IOnSceneDestroyedListener {
	public:
		IOnSceneDestroyedListener() = default;
		virtual ~IOnSceneDestroyedListener() = default;
		virtual void OnSceneDestroyed(eScene now) = 0;
	};
}