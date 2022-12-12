#ifndef RightHandRuleRobot_hpp
#define RightHandRuleRobot_hpp
#include "RightHandRuleRobot.h"

bool RightHandRuleRobot::move(Maze& lab){
    int flag=-1;
    if(!rightHand(lab)){
        contactWall(lab);
        cout<<"\nnow I'm in contact with the wall!!!\n";
    }
    else{
        cout<<"\nI'm already in contact with the wall\n";
    }
    do{
        int movx=rand() % 3 + (-1);
        int movy=rand() % 3 + (-1);
        //cout<<"\n\nrand x "<<movx<<" rand y "<<movy<<" valore in quella posizione"<<lab.getValue(2,2);
        if((movx!=0 || movy!=0) && rightHand(lab,lab.getXs()+movx,lab.getYs()+movy)){
            flag=lab.setSSpos(lab.getXs()+movx,lab.getYs()+movy);
            if(flag == -1 && nextMove(lab)) {
                cout<<"\nsorry, there are no more moves\n";
                return true;
            }
        }

    }
    while (flag==-1);

    cout<<"\n\n";
    lab.printMaze();

    if(flag==0){
        return false;
    }
    /*else if(flag==-2){
        cout<<"\nsorry, there are no more moves\n";
        return true;
    }*/
    else{
        cout<<"\ncongratulations! You win";
        return true;
    }
    return true;
}

bool RightHandRuleRobot::rightHand(Maze& lab){

    if(lab.getXs()<8 && lab.getValue(lab.getXs()+1,lab.getYs()) == '*'){
        return true;
    }
    return false;
}

bool RightHandRuleRobot::rightHand(Maze& lab,int x,int y){

    if(lab.getXs()<8 && lab.getValue(x+1,y) == '*'){
        return true;
    }
    return false;
}

bool RightHandRuleRobot::nextMove(Maze& lab){

    int i=lab.getYs(),j=lab.getXs();
    //cout<<"valori iniziale: "<<j<<" altro " <<i;
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

            if(lab.getValue(j,i) != 'S' && lab.getValue(j,i)!='*' && rightHand(lab,j,i)){
                return false;
            }
        }
        
    }
    
	return true;
}

void RightHandRuleRobot::contactWall(Maze& lab){
    int movx=0;

    do{
        movx=rand() % 100 + (-100);
    }
    while(movx==0);

    //cout<<"\n\nrand x "<<movx<<" rand y "<<movy<<" valore in quella posizione"<<lab.getValue(2,2);
    int flag=0;
    if(movx<0){
        //cout<<"\nmi muovo verso sinistra";
        int border=lab.getXs()+1;
        do{
            int movx=-(rand() % border);
            int movy=rand() % (9) + (-lab.getYs());
           //cout<<"\n\nrand x "<<movx<<"valx "<<lab.getXs()<<" somma "<<(lab.getXs()+movx)<< " rand y "<<(lab.getYs()+movy)<<" valore in quella posizione"<<lab.getValue(lab.getXs()+movx,lab.getYs()+movy);
            if((movx!=0 || movy!=0)){
                flag=lab.setSSpos(lab.getXs()+movx,lab.getYs()+movy);
            }
            if(flag==0){
                lab.printMaze();
                border=lab.getXs()+1;
            }        
            }
        while ((!rightHand(lab)) && flag!=1);
    }
    else{
       // cout<<"\nmi muovo verso destra";
        int border=9-lab.getXs();
        do{
            int movx=rand() % (border);
            int movy=rand() % (9) + (-lab.getYs());
            //cout<<"\n\nrand x "<<movx<<"valx "<<lab.getXs()<<" rand y "<<(lab.getYs()+movy)<<" valore in quella posizione"<<lab.getValue(lab.getXs()+movx,lab.getYs()+movy);
            if((movx!=0 || movy!=0)){
                flag=lab.setSSpos(lab.getXs()+movx,lab.getYs()+movy);
            }
            if(flag==0){
                lab.printMaze();
                border=9-lab.getXs();
            }
        }
        while ((!rightHand(lab)) && flag!=1);
    }
  

}


#endif