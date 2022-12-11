#ifndef RightHandRuleRobot_hpp
#define RightHandRuleRobot_hpp
#include "RightHandRuleRobot.h"

bool RightHandRuleRobot::move(Maze& lab){
    int flag=-1;
    if(!rightHand(lab)){
        contactWall(lab);
    }
    /*do{
        cout<<"noin ci entrro";
        int movx=rand() % 19 + (-9);
        int movy=rand() % 19 + (-9);
        cout<<"\n\nrand x "<<movx<<" rand y "<<movy<<" valore in quella posizione"<<lab.getValue(2,2);
        if((movx!=0 || movy!=0) ){
            flag=lab.setSSpos(lab.getXs()+movx,lab.getYs()+movy);
        }
    }
    while (flag==-1);

    cout<<"\n\n";
    lab.printMaze();

    if(flag==0){
        return false;
    }
    else{
        cout<<"\ncongratulations! You win";
        return true;
    }*/
    return true;
}

bool RightHandRuleRobot::rightHand(Maze& lab){

    if(lab.getValue(lab.getXs()+1,lab.getYs()) == '*'){
        return true;
    }
    return false;
}

void RightHandRuleRobot::contactWall(Maze& lab){
    int movx=0;

    do{
        movx=rand() % 3 + (-1);
    }
    while(movx==0);

    //cout<<"\n\nrand x "<<movx<<" rand y "<<movy<<" valore in quella posizione"<<lab.getValue(2,2);
    int flag=0;
    if(movx<0){
        cout<<"mi muovo verso sinistra";
        int border=lab.getXs();
        do{
            int movx=-(rand() % border);
            int movy=rand() % (10) + (-lab.getYs());
            //cout<<"\n\nrand x "<<movx<<" rand y "<<movy<<" valore in quella posizione"<<lab.getValue(2,2);
            if((movx!=0 || movy!=0)){
                flag=lab.setSSpos(lab.getXs()+movx,lab.getYs()+movy);
            }
            lab.printMaze();
        }
        while ((!rightHand(lab)) && flag!=1);
    }
    else{
        cout<<"mi muovo verso destra";
        int border=8-lab.getXs();
        do{
            int movx=rand() % border;
            int movy=rand() % (10) + (-lab.getYs());
            //cout<<"\n\nrand x "<<movx<<" rand y "<<movy<<" valore in quella posizione"<<lab.getValue(2,2);
            if((movx!=0 || movy!=0)){
                flag=lab.setSSpos(lab.getXs()+movx,lab.getYs()+movy);
            }
            lab.printMaze();
        }
        while ((!rightHand(lab)) && flag!=1);
    }
  

}


#endif