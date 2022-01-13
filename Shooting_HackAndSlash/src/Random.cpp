#include "Random.h"
#include<cassert>

namespace Shooting_HackAndSlash {
	bool Random::Question(int numerator, int denominator) {
		assert(numerator <= denominator);

		// ˆø”‚ÌŒ^‚ğ‡‚í‚¹‚é
		uint32_t u32_n = static_cast<uint32_t>(numerator);
		uint32_t u32_d = static_cast<uint32_t>(denominator);

		// —”‚ğæ“¾
		uint32_t rand = Random::getInstance().random_machine();

		// —”‚ğ‰ÁH
		uint32_t rand_resized = rand % u32_d;

		return rand_resized <= u32_n;
	}

	bool Random::Question(float true_rate) {
		// ”äŠr—p‚Ì”‚ğæ“¾
		uint32_t border = static_cast<uint32_t>(true_rate * Random::getInstance().random_machine.max());

		// —”‚ğæ“¾
		uint32_t rand = Random::getInstance().random_machine();

		return (rand <= border);
	}

	int Random::Range(int min, int max) {
		assert(min < max);

		// —”‚Ì‰ÁH—p‚Émin~max‚Ì’·‚³‚ğŒvZ
		// ‚Â‚¢‚Å‚ÉŒ^•ÏŠ·
		uint32_t range = static_cast<uint32_t>(max - min + 1);

		// —”‚ğæ“¾
		uint32_t rand = Random::getInstance().random_machine();

		// —”‚ğ‰ÁH
		// 0~(max-min)‚Ü‚Å‚Ì”š‚ğ•Ô‚µ‚Ä—~‚µ‚¢
		int rand_reshaped = static_cast<int>(rand % range);

		// ‰º‘Ê‚ğ—š‚©‚¹‚ÄƒŠƒ^[ƒ“
		return rand_reshaped + min;
	}
}