#pragma once

#include"AbstructScene.h"

namespace Shooting_HackAndSlash {
	namespace Scene {
		// �������Ȃ�null��փN���X
		class NullScene : public AbstructScene {
		public:
			bool update() override;
			void draw() const override;
			NullScene(ISceneChangeListener& i) : AbstructScene(i) {}
			~NullScene() = default;
		};
	}
}