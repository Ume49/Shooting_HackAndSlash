#include "KeyChecker.h"

namespace Shooting_HackAndSlash::Input_Component {
	void KeyChecker::udpate() {
		GetHitKeyStateAll(key_buf.data());

		for (UINT i = 0; i < key_buf.size(); i++) {
			if (key_buf.at(i) == TRUE) {
				key_count.at(i)++;
			}
			else {
				if (key_count.at(i) > 0) {
					key_count.at(i) = -1;
				}
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