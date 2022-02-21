#pragma once
#include"Vector.h"

namespace Shooting_HackAndSlash {
	/**
	 * @brief UIオブジェクトの基底クラス
	 */
	class Abstruct_UI {
	protected:
		Point pos;
	public:
		/**
		 * @brief 描画呼び出し
		 */
		virtual void draw() const = 0;

		Abstruct_UI() : pos() {}
		Abstruct_UI(const Point& pos) : pos(pos) { }
		virtual ~Abstruct_UI() = default;
	};
}
