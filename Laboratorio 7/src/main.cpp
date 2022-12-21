//Battistin Claudio 
#include <iostream>
#include <stdio.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <cstdlib>
#include "RandomRobot.h"
#include "RightHandRuleRobot.h"

int main(void) {
    
    Maze m("Labirinto.txt");
    RandomRobot r;
    
    while(!r.move(m)){
        r.addAttempts();
    }

    cout<<"\nAttempts "<<r.getAttempts();
    Sleep(5000);
    Maze m2("Labirinto.txt");
    RightHandRuleRobot right;
    
    while(!right.move(m2)){
        right.addAttempts();
    }
     cout<<"\nAttempts "<<right.getAttempts();
    return 0;
}
