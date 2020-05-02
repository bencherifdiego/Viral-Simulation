#include "RegularMovementStrategy.h"

namespace corsim
{
    int RegularMovementStrategy::move(int dt, std::vector<Subject> &subjects)
    {
        int numberInfected = 0;
        for(Subject& s : subjects)
        {
            s.set_x(s.x() + s.dx() * dt);
            s.set_y(s.y() + s.dy() * dt);
            if(s.infected())
            {
                numberInfected++;
            }
        }
        return numberInfected;
    }
}