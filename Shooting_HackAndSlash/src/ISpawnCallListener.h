#pragma once

namespace Shooting_HackAndSlash{
	// �X�|�[���֐����Ăяo�����߂̃C���^�[�t�F�[�X
	class ISpawnCallListener {
	public:
		// �Ăяo��
		virtual void call_spawn() = 0;

		ISpawnCallListener() = default;
		virtual ~ISpawnCallListener() = default;
	};
}
