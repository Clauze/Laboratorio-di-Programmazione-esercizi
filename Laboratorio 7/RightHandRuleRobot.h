#ifndef RightHandRuleRobot_h
#define RightHandRuleRobot_h
#include "Robot.cpp"

class RightHandRuleRobot : public Robot{
    private:
        
    public:
        bool move(Maze& lab) override;
        bool rightHand(Maze& lab);
        bool nextMove(Maze& lab) override;
        bool rightHand(Maze& lab,int x,int y);
        void contactWall(Maze& lab);
};
#include "RightHandRuleRobot.hpp"
#endif