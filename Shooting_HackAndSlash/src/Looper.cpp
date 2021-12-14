#include "Looper.h"

#include<DxLib.h>

#include"Time.h"
#include"Input.h"

namespace Shooting_HackAndSlash {
	bool Looper::loop() {
		Time::update();
		Input::update();

		bool temp = scene.load();

#ifdef _DEBUG
		if (Input::GetDown(Inputcode::Debug_Exit)) return false;
#endif // _DEBUG
		return temp;
	}

	Looper::Looper() :
		scene() {
	}
}