#pragma once

namespace Shooting_HackAndSlash {
	class IEraseIcon {
	public:
		IEraseIcon() = default;
		virtual ~IEraseIcon() = default;

		virtual void EraseIcon() = 0;
	};
}