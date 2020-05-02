#pragma once

#include "MovementStrategy.h"


namespace corsim
{
    class RegularMovement: public MovementStrategy
    {
        public:
        int move(int dt, std::vector<Subject> &subjects);
    };

    class LockdownMovement: public MovementStrategy
    {
        public:
        int move(int dt, std::vector<Subject> &subjects);
        private:
        bool run;
    };
}