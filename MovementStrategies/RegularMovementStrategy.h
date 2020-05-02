#pragma once

#include "MovementStrategy.h"


namespace corsim
{
    class RegularMovementStrategy: public MovementStrategy
    {
        public:
        int move(int dt, std::vector<Subject> &subjects);
    };
}