#include "LockdownMovementStrategy.h"

namespace corsim
{
    int LockdownMovementStrategy::move(int dt, std::vector<Subject> &subjects)
    {
        if (run == NULL)
        {
            int num = subjects.size()/4*3;
            for (int i = 0; i < num; i++)
            {
                subjects.at(i).setLocked(true);
            }
            run = true;
        }

        int numberInfected = 0;
        for(Subject& s : subjects)
        {
            if (s.getLocked() != true)
            {
            s.set_x(s.x() + s.dx() * dt);
            s.set_y(s.y() + s.dy() * dt);
            }
            if(s.infected())
            {
                numberInfected++;
            }
        }
        return numberInfected;
    }
}