#pragma once

#include"IDisplayer.h"

#include<string>

namespace Shooting_HackAndSlash {
	// 見た目をテキストで表示するクラス
	class TextDisplayer : public IDisplayer {
	private:
		std::string me;
		Vec2 half_size;
		uint32_t color;

		void init();
	public:
		void display(const Vec2& pos, const Vec2& direction) const override;

		TextDisplayer(const std::string& header, uint32_t color) :
			me(header),
			half_size(),
			color(color) {
			init();
		}
	};
}
