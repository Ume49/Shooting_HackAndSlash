#pragma once

#include"Vector.h"

namespace Shooting_HackAndSlash {
    namespace UI {
        class Bomb_count_displayer {
        private:
            static constexpr unsigned int COLOR = 0x000000;

            Point pos;
        public:
            void draw() const;

            Bomb_count_displayer() : pos(660, 770){}
        };
    }
}