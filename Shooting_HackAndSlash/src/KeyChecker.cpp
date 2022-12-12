#include "KeyChecker.h"

namespace Shooting_HackAndSlash::Input_Component {
	void KeyChecker::udpate() {
		GetHitKeyStateAll(key_buf.data());

		// 各キーが連続して押されているフレーム数をインクリメント
		// 押され続けているなら+1、
		// もう押されていないなら0にする
		// 「キーから指が離れた瞬間」のみ、－1にする
		for (UINT i = 0; i < key_buf.size(); i++) {
			// 押され続けている
			if (key_buf.at(i) == TRUE) {
				key_count.at(i)++;
			}
			else {
				// キーを指から離したとき
				if (key_count.at(i) > 0) {
					key_count.at(i) = -1;
				}
				// もう押されていないのでリセット
				else if (key_count.at(i) == -1) {
					key_count.at(i) = 0;
				}
			}
		}
	}

	bool KeyChecker::GetKey(const int key) const {
		return key_count.at(key) > 0;
	}

	bool KeyChecker::GetKeyDown(const int key) const {
		return key_count.at(key) == 1;
	}

	bool KeyChecker::GetKeyUp(const int key) const {
		return key_count.at(key) == -1;
	}
}