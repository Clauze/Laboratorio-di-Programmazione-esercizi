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
            //cout<<"  ora chiamo\n";

            flag=lab.setSSpos(lab.getXs()+movx,lab.getYs()+movy);
            //cout<<"\n\nposizione xs "<<lab.getXs()<< " ys " <<lab.getYs()<<"\n";
           // cout<<"ora controllo\n\n";

            if(flag == -1 && nextMove(lab)) {
                cout<<"\nsorry, there are no more moves\n";
                return true;
            }

        }
    }
    while (flag==-1);
    /*system("CLS");
    system("clear");*/
    cout<<"\n\n";
    lab.printMaze();
    if(flag==0){
        return false;
    }
    else{
        cout<<"\ncongratulations! You win";
        return true;
    }
}

bool RandomRobot::nextMove(Maze& lab){

    int i=lab.getYs(),j=lab.getXs();
    cout<<"valori iniziale: "<<j<<" altro " <<i;
    if(lab.getYs() == 0){
        i++;
    }
    if(lab.getXs() == 0){
        j++;
    }

    for (i--; (i < lab.getYs() + 2) && i < 9  ; i++)
    {

        cout<<"\n";
        
        for (j--; (j < lab.getXs() + 2) && j < 9; j++)
        {
            //cout<<" "<<lab.getValue(j,i)<<" in x y:"<<j<<" "<<i;

            if(lab.getValue(j,i) != 'S' && lab.getValue(j,i)!='*'){
                return false;
            }
        }
        
    }
    
	return true;
}

#endif