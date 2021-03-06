#include "Strategies.h"

namespace corsim
{
    int RegularMovement::move(int dt, std::vector<Subject> &subjects, int week)
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

    int LockdownMovement::move(int dt, std::vector<Subject> &subjects, int week)
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

        for (Subject& s : subjects)
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

    int SmartLockdownMovement::move(int dt, std::vector<Subject> &subjects, int week)
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

        if (week > 15 && week < 35)
        {
            int num = week-15;
            for (int i = 0; i < num; i++)
            {
                for (int i = 0; i < num*10; i++)
                {
                    subjects.at(i).setLocked(false);
                }
            }
            
        }

        int numberInfected = 0;

        for (Subject& s : subjects)
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

    int RegenMovement::move(int dt, std::vector<Subject> &subjects, int week)
    {
        int numberInfected = 0;
        for(Subject& s : subjects)
        {
            if (s.timer > 0)
            {
                s.timer--;
                if (s.timer == 0)
                {
                    s.deInfect();
                }
            }
            if (s.timer2 > 0)
            {
                s.timer2--;
            }
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