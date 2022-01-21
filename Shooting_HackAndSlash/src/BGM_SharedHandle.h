#pragma once

#include"Abstruct_Shared_Handle.h"

namespace Shooting_HackAndSlash {
	class BGM_SharedHandle : public Abstruct_SharedHandle{
	public:
		BGM_SharedHandle(const std::string& file_path);
		~BGM_SharedHandle() = default;
	};
}
