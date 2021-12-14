#include "Color.h"
#include<DxLib.h>

#include<cassert>
#include<cmath>
#include<algorithm>

namespace {
	// 初期化に使う色
	constexpr unsigned int NULL_COLOR = 0x000000;

	constexpr int SHIFT_RED = 16;
	constexpr int SHIFT_GREEN = 8;
	constexpr int SHIFT_BLUE = 0;
}

namespace Shooting_HackAndSlash {
	Color::operator unsigned int() const noexcept {
		return code;
	}

	Color& Color::operator=(unsigned int r) {
		code = r;
		return *this;
	}

	Color::Color() :
		code(NULL_COLOR) {
	}

	Color::Color(unsigned int color) :
		code(color) {
	}

	Color::Color(int r, int g, int b) :
		code()
	{
		code = GetColor(r, g, b);
	}

	int Color::Red() const {
		return static_cast<int>((code & 0xff0000) >> SHIFT_RED);
	}

	int Color::Green() const {
		return static_cast<int>((code & 0x00ff00) >> SHIFT_BLUE);
	}

	int Color::Blue() const {
		return static_cast<int>(code & 0x0000ff);
	}

	void Color::AddRed(int r) {
		assert(std::abs(r) > 255);

		// codeから成分を抜き出し
		int now_r = Red();
		code &= 0x00ffff;

		// codeに代入
		code += std::clamp(static_cast<unsigned int>((now_r + r) % 255), 0U, 255U) << SHIFT_RED;
	}

	void Color::AddGreen(int g) {
		assert(std::abs(g) > 255);

		// codeから成分抜き出し
		int now_g = Green();
		code &= 0xff00ff;

		// codeに代入
		code += std::clamp(static_cast<unsigned int>((now_g + g) % 255), 0U, 255U) << SHIFT_GREEN;
	}

	void Color::AddBlue(int b) {
		assert(std::abs(b) > 255);

		// codeから成分抜き出し
		int now_b = Blue();

		// codeに代入
		code += std::clamp(static_cast<unsigned int>((now_b + b) % 255), 0U, 255U);
	}
}