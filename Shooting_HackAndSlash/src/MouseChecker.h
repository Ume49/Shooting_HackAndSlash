#pragma once

#include<array>
#include<algorithm>
#include"Vector.h"

namespace Shooting_HackAndSlash {
    namespace Input_Component {
        // マウスボタンの押下状況を監視するクラス
        // Inputクラスにメンバとして利用される
        class MouseChecker {
        private:
            std::array<int, 3> count;
        public:
            void update();

            bool GetInput(const int MOUSE_INPUT_) const;
            bool GetDown (const int MOUSE_INPUT_) const;
            bool GetUp   (const int MOUSE_INPUT_) const;

            MouseChecker();
            ~MouseChecker() = default;
        };
    }
}