#include "Fade.h"
#include<DxLib.h>
#include"Color.h"
#include"Time.h"
#include<algorithm>

namespace {
	using namespace Shooting_HackAndSlash;
	// 画面の明るさの初期値
	constexpr int init_bright = 255;

	// 明るさの減少量
	constexpr float bright_decrease = 120.f;
}

namespace Shooting_HackAndSlash {
	Fade::Fade() :
		state(State::Wait),
		bright(init_bright) {
	}

	bool Fade::update() {
		bool flag = false;

		// 明るさを変更する
		auto change = [](int b) { SetDrawBright(b, b, b); };

		switch (state) {
		case State::Wait:
			// 待機状態なので何もしない
			break;
		case State::Fade:
			bright -= ::bright_decrease * Time::DeltaTime();
			{
				int temp = std::clamp(static_cast<int>(bright), 0, 255);

				//change(temp);
				SetDrawBright(temp, temp, temp);

				if (temp == 0) {
					state = State::Reset;
				}
			}
			break;
		case State::Reset:
			bright = static_cast<float>(init_bright);
			change(init_bright);

			state = State::Wait;
			flag = true;
			break;
		}

		return flag;
	}

	void Fade::Set() {
		state = State::Fade;
	}
}