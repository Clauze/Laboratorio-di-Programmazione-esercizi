//Battistin Claudio 
#include <iostream>
#include "Maze.h"
#include "RandomRobot.h"
#include "RightHandRuleRobot.h"

int main(void) {
    
    Maze m("Labirinto.txt");
    /*RandomRobot r;
    
    while(!r.move(m)){
        //r.move(m);
        r.addAttempts();
    }

    cout<<"\nAttempts "<<r.getAttempts();*/

    RightHandRuleRobot r;
    
    while(!r.move(m)){
        //r.move(m);
        //r.addAttempts();
    }

    return 0;
}
