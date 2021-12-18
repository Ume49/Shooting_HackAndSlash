#include"Gun_Custamize_Window.h"
#include"Input.h"

namespace {
	namespace BackPack {
		// �o�b�N�p�b�N���ǂ��ɕ\������̂�
		// �����̐�΍��W
		constexpr int x = 500, y = 300;
	}
}

namespace Shooting_HackAndSlash {
	Gun_Custamize_Window::Gun_Custamize_Window() :
		backpack(Point{ ::BackPack::x, ::BackPack::y }, *this),
		magazine(),
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

	void Gun_Custamize_Window::SetIcon(const eBullet& b) {
		icon = std::make_unique<Dragged_Icon>(b);
	}

	void Gun_Custamize_Window::EraseIcon() {
		icon = std::make_unique<Dragged_Icon_Null>();
	}
}