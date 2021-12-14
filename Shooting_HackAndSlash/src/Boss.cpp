#include "Boss.h"

#include<DxLib.h>

namespace Shooting_HackAndSlash {
	namespace Scene {
		Boss::Boss(ISceneChangeListener& s) :
			AbstructScene(s) {

		}

		void Boss::draw() const{
		}

		bool Boss::update() {

			return true;
		}
	}
}