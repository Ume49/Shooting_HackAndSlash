#pragma once

#include"BGM_SharedHandle.h"

namespace Shooting_HackAndSlash {
	// BGMƒvƒŒƒCƒ„[
	// íœ‚³‚ê‚é‚É©“®‚Å~‚ß‚é
	// ’†’f‚µ‚Ä‚©‚ç‚ÌÄ¶‚Í‘O‰ñ~‚ß‚½êŠ‚©‚çÄ¶‚³‚ê‚é
	class BGM_Player {
		BGM_SharedHandle handle;
	public:
		BGM_Player(const std::string& file_path);
		~BGM_Player();

		// BGMÄ¶
		void play() const;
		// Ä¶‚µ‚Ä‚¢‚éBGM‚ğ’†~‚·‚é
		void stop() const;
	};
}
