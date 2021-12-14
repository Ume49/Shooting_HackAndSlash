#include "ButtonController.h"

namespace Shooting_HackAndSlash {
    void ButtonController::update() {
        for (auto& w : buttons) {
            w.update();
        }
    }

    void ButtonController::draw() const {
        for (auto& w : buttons) {
            w.draw();
        }
    }

    void ButtonController::Add(std::function<void(void)> onclick, const std::string& text, const Point& p_leftup) {
        buttons.push_back(UI::Button(onclick, text, p_leftup));
    }
}