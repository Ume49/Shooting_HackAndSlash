#pragma once

// デバッグ中だけ使われるパラメータ

#ifdef _DEBUG
namespace Shooting_HackAndSlash{
	namespace Palette {
		constexpr unsigned int Collider = 0xff00ff;
	}
	namespace Font_Test {
		constexpr char Name[] = "BIZ UDPゴシック";
		// DX_FONTTYPE_ANTIALIASING_4X4と同値
		constexpr int Type = 0x12;
	}
}
#endif // _DEBUG
