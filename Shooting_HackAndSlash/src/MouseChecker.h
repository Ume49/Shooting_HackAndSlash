#pragma once

#include<array>
#include<algorithm>
#include"Vector.h"

namespace Shooting_HackAndSlash {
    namespace Input_Component {
        // �}�E�X�{�^���̉����󋵂��Ď�����N���X
        // Input�N���X�Ƀ����o�Ƃ��ė��p�����
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