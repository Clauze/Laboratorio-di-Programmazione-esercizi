#ifndef RobotRobot_hpp
#define RobotRobot_hpp
#include "RandomRobot.h"

bool RandomRobot::move(Maze& lab){
    int flag=-1;
    do{
        int movx=rand() % 3 + (-1);
        int movy=rand() % 3 + (-1);
        //cout<<"\n\nrand x "<<movx<<" rand y "<<movy;
        if(movx!=0 || movy!=0){
            //out<<"  ora chiamo\n";
            flag=lab.setSSpos(lab.getXs()+movx,lab.getYs()+movy);
        }
    }
    while (flag==-1);
    /*system("CLS");
    system("clear");*/
    cout<<"\n\n";
    lab.printMaze();
    //cout<<"\nx pos "<<lab.getXs()<<" y pos "<<lab.getYs();
    if(flag==0){
        return false;
    }
    else{
        cout<<"\ncongratulations! You win";
        return true;
    }
}

#endif