#pragma once

namespace Shooting_HackAndSlash {
	// 色情報として使用するunsigned int型のラッパー構造体
	// RGBで動作
	struct Color{
	private:
		unsigned int code;
	public:
		// 赤成分だけ返す
		int Red() const;
		// 緑成分だけ返す
		int Green() const;
		// 青成分だけ返す
		int Blue() const;

		// 赤成分に対して和算
		// 値は0~255をはみ出さないように処理される
		void AddRed(int r);
		// 緑成分に対して和算
		// 値は0~255をはみ出さないように処理される
		void AddGreen(int g);
		// 青成分に対して和算
		// 値は0~255をはみ出さないように処理される
		void AddBlue(int b);

		operator unsigned int() const noexcept;
		Color& operator=(unsigned int r);
		Color(unsigned int color_code);
		Color(int r, int g, int b);
		Color();
		~Color() = default;
	};
}
