//Battistin Claudio 
#include <iostream>
#include "Maze.h"
#include "RandomRobot.h"
#include "RightHandRuleRobot.h"

int main(void) {
    
    Maze m("Labirinto.txt");
    RandomRobot r;
    
    while(!r.move(m)){
        r.addAttempts();
    }

    cout<<"\nAttempts "<<r.getAttempts();
    
    Maze m2("Labirinto.txt");
    RightHandRuleRobot right;
    
    while(!right.move(m2)){
        right.addAttempts();
    }
     cout<<"\nAttempts "<<right.getAttempts();
    return 0;
}
