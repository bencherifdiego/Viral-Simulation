#pragma once

#include "MovementStrategy.h"

namespace corsim
{
    class LockdownMovementStrategy: public corsim::MovementStrategy
    {
        public:
        int move(int dt, std::vector<Subject> &subjects);
        private:
        bool run;
    };
}