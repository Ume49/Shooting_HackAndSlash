#pragma once
#include"Vector.h"

namespace Shooting_HackAndSlash {
	/**
	 * @brief UI�I�u�W�F�N�g�̊��N���X
	 */
	class Abstruct_UI {
	protected:
		Point pos;
	public:
		/**
		 * @brief �`��Ăяo��
		 */
		virtual void draw() const = 0;

		Abstruct_UI() : pos() {}
		Abstruct_UI(const Point& pos) : pos(pos) { }
		virtual ~Abstruct_UI() = default;
	};
}
