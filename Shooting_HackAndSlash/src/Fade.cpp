#include "Fade.h"
#include<DxLib.h>
#include"Color.h"
#include"Time.h"
#include<algorithm>

namespace {
	using namespace Shooting_HackAndSlash;
	// ‰æ–Ê‚Ì–¾‚é‚³‚Ì‰Šú’l
	constexpr int init_bright = 255;

	// –¾‚é‚³‚ÌŒ¸­—Ê
	constexpr float bright_decrease = 120.f;
}

namespace Shooting_HackAndSlash {
	Fade::Fade() :
		state(State::Wait),
		bright(init_bright) {
	}

	bool Fade::update() {
		bool flag = false;

		// –¾‚é‚³‚ğ•ÏX‚·‚é
		auto change = [](int b) { SetDrawBright(b, b, b); };

		switch (state) {
		case State::Wait:
			// ‘Ò‹@ó‘Ô‚È‚Ì‚Å‰½‚à‚µ‚È‚¢
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