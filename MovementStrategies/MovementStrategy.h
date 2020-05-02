#pragma once

#include <vector>
#include "../simulation.h"

namespace corsim
{
    class MovementStrategy
    {
        public:
        virtual int move(int dt, std::vector<Subject> &subjects) = 0;
    };
}