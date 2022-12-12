#include "KeyChecker.h"

namespace Shooting_HackAndSlash::Input_Component {
	void KeyChecker::udpate() {
		GetHitKeyStateAll(key_buf.data());

		// �e�L�[���A�����ĉ�����Ă���t���[�������C���N�������g
		// �����ꑱ���Ă���Ȃ�+1�A
		// ����������Ă��Ȃ��Ȃ�0�ɂ���
		// �u�L�[����w�����ꂽ�u�ԁv�̂݁A�|1�ɂ���
		for (UINT i = 0; i < key_buf.size(); i++) {
			// �����ꑱ���Ă���
			if (key_buf.at(i) == TRUE) {
				key_count.at(i)++;
			}
			else {
				// �L�[���w���痣�����Ƃ�
				if (key_count.at(i) > 0) {
					key_count.at(i) = -1;
				}
				// ����������Ă��Ȃ��̂Ń��Z�b�g
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