#pragma once

#include<array>
#include<algorithm>

#include<DxLib.h>

namespace Shooting_HackAndSlash {
	namespace Input_Component {
		// キーボードの押下状況を監視するクラス
		class KeyChecker {
		private:
			std::array<int, 256> key_count;
			std::array<char, 256> key_buf;
		public:
			void udpate();

			bool GetKey(const int keycode) const;
			bool GetKeyDown(const int keycode) const;
			bool GetKeyUp(const int keycode) const;

			KeyChecker() :
				key_count(),
				key_buf() {
				std::fill(key_count.begin(), key_count.end(), 0);
			}
		};
	}
}