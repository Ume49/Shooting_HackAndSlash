#pragma once

namespace Shooting_HackAndSlash {
	class Fade{
		enum class State{
			Wait, Fade, Reset
		} state;

		float bright;
	public:
		// �t�F�[�h�I�����̂݁Atrue��Ԃ�
		bool update();

		// ������Z�b�g
		void Set();

		Fade();
		~Fade() = default;
	};
}
