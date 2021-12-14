#pragma once

#include"ISceneChangListener.h"

namespace Shooting_HackAndSlash {
	class AbstructScene {
	protected:
		ISceneChangeListener& listener;
	public:
		virtual bool update() = 0;
		virtual void draw() const = 0;
		AbstructScene(ISceneChangeListener& l) : listener(l) {}
		virtual ~AbstructScene() = default;
	};
}
