#pragma once

#include"SE_SharedHandle.h"

namespace Shooting_HackAndSlash {
	// 効果音プレイヤー
	// これには一つのファイルしか登録できないので、再生したい音声ファイルの数だけこのインスタンスを作成する必要がある
	class SE_Player{
		SE_SharedHandle handle;
	public:
		SE_Player(const std::string& file_path);
		~SE_Player();

		// 登録された効果音を再生する
		// これを呼び出したら効果音ファイルの最後まで再生される
		void play() const;
	};
}
