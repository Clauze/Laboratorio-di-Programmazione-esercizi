#ifndef RobotRobot_h
#define RobotRobot_h
#include "Robot.cpp"

class RandomRobot: public Robot{
    private:

    public:
        bool move(Maze& lab) override;
        bool nextMove(Maze& lab) override;
};
#include "RandomRobot.hpp"
#endif
