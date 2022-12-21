//Battistin Claudio 
#ifndef RightHandRuleRobot_hpp
#define RightHandRuleRobot_hpp

bool RightHandRuleRobot::move(Maze& lab){
    int flag=-1;
    
    if(!rightHand(lab)){
        contactWall(lab);
    }

    do{
        int movx=rand() % 3 + (-1);
        int movy=rand() % 3 + (-1);

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

    int i=lab.getYs(), j=lab.getXs(), initaliJ=0;

    if(lab.getYs() == 0){
        i++;
    }
    if(lab.getXs() == 0){
        j++;
    }

    initaliJ=j;

    for (i--; (i < lab.getYs() + 2) && i < 9  ; i++)
    {

        
        for (j--; (j < lab.getXs() + 2) && j < 9; j++)
        {

            if(lab.getValue(j,i) != 'S' && lab.getValue(j,i)!='*' && rightHand(lab,j,i)){
                return false;
            }

        }

        j=initaliJ;
        
    }
    
	return true;
}

void RightHandRuleRobot::contactWall(Maze& lab){
    int movx=0;

    do{
        movx=rand() % 100 + (-100);
    }
    while(movx==0);


    int flag=0;

    if(movx<0){

        int border=lab.getXs()+1;
        do{

            int movx=-(rand() % border);
            int movy=rand() % (9) + (-lab.getYs());

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

        int border=9-lab.getXs();
        do{
            int movx=rand() % (border);
            int movy=rand() % (9) + (-lab.getYs());

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