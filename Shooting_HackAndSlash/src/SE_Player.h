#pragma once

#include"SE_SharedHandle.h"

namespace Shooting_HackAndSlash {
	// Œø‰Ê‰¹ƒvƒŒƒCƒ„[
	class SE_Player{
		SE_SharedHandle handle;
	public:
		SE_Player(const std::string& file_path);
		~SE_Player();

		void play() const;
	};
}
