#pragma once

#include"SceneLoader.h"

namespace Shooting_HackAndSlash {
	// ���C�����[�v�������Ăяo���N���X
	class Looper {
	private:
		SceneLoader scene;
	public:
		// �Q�[���̃��C�����[�v
		bool loop();

		Looper();
		~Looper() = default;
	};
}