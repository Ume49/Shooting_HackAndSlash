#include"Gun_Custamize_Window.h"
#include"Input.h"

namespace {
	namespace BackPack {
		// バックパックをどこに表示するのか
		// 左上基準の絶対座標
		constexpr int x = 500, y = 300;
	}
}

namespace Shooting_HackAndSlash {
	using namespace Gun_Custamize;

	Gun_Custamize_Window::Gun_Custamize_Window() :
		backpack(Point{ ::BackPack::x, ::BackPack::y }, * this),
		magazine(*this),
		icon() {
		icon = std::make_unique<Dragged_Icon_Null>();
	}

	void Gun_Custamize_Window::update() {
		backpack.update();
		magazine.update();
		icon->update();
	}

	void Gun_Custamize_Window::draw() const {
		backpack.draw();
		magazine.draw();
		icon->draw();
	}

	void Gun_Custamize_Window::SetIcon(const eBullet& b, IBackListener& back, size_t i) {
		icon = std::make_unique<Dragged_Icon>(b, i, *this, back, magazine, backpack);
	}

	void Gun_Custamize_Window::EraseIcon() {
		icon = std::make_unique<Dragged_Icon_Null>();
	}
}