#pragma once

#include"SE_SharedHandle.h"

namespace Shooting_HackAndSlash {
	// ���ʉ��v���C���[
	class SE_Player{
		SE_SharedHandle handle;
	public:
		SE_Player(const std::string& file_path);
		~SE_Player();

		void play() const;
	};
}
