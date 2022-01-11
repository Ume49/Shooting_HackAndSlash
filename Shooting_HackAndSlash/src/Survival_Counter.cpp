#include "Survival_Counter.h"

#include"Time.h"

namespace Shooting_HackAndSlash {
	bool Survival_Counter::is_end() {
		count -= Time::DeltaTime();

		return count <= 0.f;
	}

	Survival_Counter::Survival_Counter(float c) :
		count(c) {
	}
}