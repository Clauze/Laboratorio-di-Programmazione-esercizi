//Battistin Claudio
#ifndef Robot_h
#define Robot_h
#include "Maze.h"

class Robot{
    protected:
        int att{0};
    public:
        virtual bool move(Maze& lab) = 0;
        virtual bool nextMove(Maze& lab) = 0;
        void addAttempts(){att++;};
        int getAttempts(){return att;};
};
#endif