#include "Random.h"
#include<cassert>

namespace Shooting_HackAndSlash {
	bool Random::Question(int numerator, int denominator) {
		assert(numerator <= denominator);

		// �����̌^�����킹��
		uint32_t u32_n = static_cast<uint32_t>(numerator);
		uint32_t u32_d = static_cast<uint32_t>(denominator);

		// �������擾
		uint32_t rand = Random::getInstance().random_machine();

		// ���������H
		uint32_t rand_resized = rand % u32_d;

		return rand_resized <= u32_n;
	}

	bool Random::Question(float true_rate) {
		// ��r�p�̐����擾
		uint32_t border = static_cast<uint32_t>(true_rate * Random::getInstance().random_machine.max());

		// �������擾
		uint32_t rand = Random::getInstance().random_machine();

		return (rand <= border);
	}

	int Random::Range(int min, int max) {
		assert(min < max);

		// �����̉��H�p��min~max�̒������v�Z
		// ���łɌ^�ϊ�
		uint32_t range = static_cast<uint32_t>(max - min + 1);

		// �������擾
		uint32_t rand = Random::getInstance().random_machine();

		// ���������H
		// 0~(max-min)�܂ł̐�����Ԃ��ė~����
		int rand_reshaped = static_cast<int>(rand % range);

		// ���ʂ𗚂����ă��^�[��
		return rand_reshaped + min;
	}
}