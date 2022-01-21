#pragma once

#include"Abstruct_Shared_Handle.h"

namespace Shooting_HackAndSlash {
	class SE_SharedHandle : public Abstruct_SharedHandle{
	public:
		SE_SharedHandle(const std::string& file_path);
		~SE_SharedHandle() = default;
	};
}
