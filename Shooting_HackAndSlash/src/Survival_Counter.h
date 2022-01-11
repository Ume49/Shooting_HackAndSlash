#pragma once

namespace Shooting_HackAndSlash {
	// ¶‘¶ŠÔ‚ÌI—¹‚ğŠÇ—‚·‚é
	class Survival_Counter{
		float count;
	public:
		Survival_Counter(float survival_time);
		~Survival_Counter() = default;

		// ¶‘¶ŠÔ‚ªI—¹‚µ‚Ä‚¢‚é‚Ì‚©
		bool is_end();
	};
}
