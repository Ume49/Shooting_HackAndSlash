#include<DxLib.h>
#include"NullScene.h"
#include"Define.h"

namespace Shooting_HackAndSlash::Scene {
	bool NullScene::update() {
		return true;
	}

	void NullScene::draw() const {
		DrawString(10, 10, "Error: Scene Stack is Null.\nHere is NullScene.", Palette::White);
	}
}