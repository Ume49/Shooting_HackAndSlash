#include "MouseChecker.h"

#include<DxLib.h>

namespace Shooting_HackAndSlash::Input_Component {
	MouseChecker::MouseChecker() :
		count()
	{
		std::fill(count.begin(), count.end(), 0);
	}

	void MouseChecker::update() {
		int mouse_input = GetMouseInput();

		// カウンタ更新関数
		auto count_update = [&](int code, int& target) {
			if (mouse_input & code) {
				target++;
			}
			else {
				if (target > 0) {
					target = -1;
				}
				else if (target == -1) {
					target = 0;
				}
				// 0の時は0を代入する代わりに何もしない
			}
		};

		count_update(MOUSE_INPUT_LEFT, count.at(MOUSE_INPUT_LEFT));
		count_update(MOUSE_INPUT_RIGHT, count.at(MOUSE_INPUT_RIGHT));
	}

	bool MouseChecker::GetInput(const int code)const {
		return count.at(code) > 0;
	}

	bool MouseChecker::GetDown(const int code)const {
		return count.at(code) == 1;
	}

	bool MouseChecker::GetUp(const int code)const {
		return count.at(code) == -1;
	}
}