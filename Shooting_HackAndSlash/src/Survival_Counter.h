#pragma once

namespace Shooting_HackAndSlash {
	// �������Ԃ̏I�����Ǘ�����
	class Survival_Counter{
		float count;
	public:
		Survival_Counter(float survival_time);
		~Survival_Counter() = default;

		// �������Ԃ��I�����Ă���̂�
		bool is_end();
	};
}
