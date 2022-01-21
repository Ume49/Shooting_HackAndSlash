#pragma once

#include"BGM_SharedHandle.h"

namespace Shooting_HackAndSlash {
	// BGMプレイヤー
	// 削除される時に自動で止める
	// 中断してからの再生は前回止めた場所から再生される
	class BGM_Player {
		BGM_SharedHandle handle;
	public:
		BGM_Player(const std::string& file_path);
		~BGM_Player();

		void play() const;
		void stop() const;
	};
}
