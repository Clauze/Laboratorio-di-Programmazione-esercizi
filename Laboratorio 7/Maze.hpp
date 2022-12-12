#ifndef Maze_hpp
#define Maze_hpp
#include <string>
#include <iostream>
#include <fstream>
#include "Maze.h"
using namespace std;

Maze::Maze(string f)
:file{f},xs{-1},ys{-1},xe{-1},ye{-1}
{
	fillMatrix();
};

bool Maze::fillMatrix(){
	ifstream myfile (file);
	if(myfile.is_open()){
		string myText;
		int i=0;
		while (getline (myfile, myText)) {
			for(int j=0;j<matrixDim;j++){
				matrix[i][j]=myText[j];
				if(myText[j] == 'S'){
					ys=i;
					xs=j;
					cout<<"\ns si trova in y"<<i<<" x "<<j;
				}
				else if(myText[j] == 'E'){
					ye=i;
					xe=j;
					cout<<"\ne si trova in y"<<i<<" x "<<j;

				}
			}
			i++;
		}

	}

	cout<<"\nstarting maze \n";
	printMaze();

	myfile.close();
	return true;
}

void Maze::printMaze(){
	//system("CLS");
   // system("clear");
   	cout<<"\n\n";
	for (int i=0;i<matrixDim;i++) {
		if(i==0){
			cout<<"  ";
			for(int j=0;j<matrixDim;j++){
				cout<<j<<" ";
			}

		}
		cout<<"\n"<<i;
		for(int j=0;j<matrixDim;j++){
			cout<<" "<<matrix[i][j];
		}


	}
}

int Maze::getXs()const{
	return xs;
}

int Maze::getYs()const{
	return ys;
}

int Maze::getXe()const{
	return xe;
}

int Maze::getYe()const{
	return ye;
}

char Maze::getValue(int x,int y)const{
	return matrix[y][x];
}


int Maze::setSSpos(int nx,int ny){
	if((nx>=0 && ny >=0) && (nx<matrixDim && ny<matrixDim)){
		/*cout<<"\nval validi\n"<<xs<<" valori precedenti "<<ys<<"\n"<<nx<<" valori ora "<<ny;
		cout<<"\n valore:"<<matrix[ny][nx]<<";"<<"o in ascii "<<int(matrix[ny][nx])<<"\n";
		*/if(int(matrix[ny][nx]) == 32){
			matrix[ny][nx]='S';
			matrix[ys][xs]=' ';
			xs=nx;
			ys=ny;
			return 0;
		}
		else if(matrix[ny][nx] == 'E'){
			matrix[ny][nx]='S';
			matrix[ys][xs]=' ';
			xs=nx;
			ys=ny;
			return 1;
		}
	}
	return -1;
}

int Maze::setSRightPos(int nx,int ny){
	if((nx>=0 && ny >=0) && (nx<matrixDim && ny<matrixDim)){
		/*cout<<"\nval validi\n"<<xs<<" valori precedenti "<<ys<<"\n"<<nx<<" valori ora "<<ny;
		cout<<"\n valore:"<<matrix[ny][nx]<<";"<<"o in ascii "<<int(matrix[ny][nx])<<"\n";
		*/if(int(matrix[ny][nx]) == 32){
			matrix[ny][nx]='S';
			matrix[ys][xs]=' ';
			xs=nx;
			ys=ny;
			return 0;
		}
		else if(matrix[ny][nx] == 'E'){
			matrix[ny][nx]='S';
			matrix[ys][xs]=' ';
			xs=nx;
			ys=ny;
			return 1;
		}
	}
	return -1;
}

#endif
/*

#include <iostream>

using namespace std;

int main()
{
    int i=0,maxx=-100,minx=100,maxy=-100,miny=100;
    while(i<300){
        int movx=-(rand() % (4));
        int movy=rand() % (9) + (-6);
        if(minx>movx){
            minx=movx;
        }
        else if(maxx<movx){
            maxx=movx;
        }
        if(miny>movy){
            miny=movy;
        }
        else if(maxy<movy){
            maxy=movy;
        }
        cout<<"\n\nrand x "<<movx<<" rand y "<<movy;
        i++;
    }
    cout<<"\n\nmin x :"<<minx<<" max x:  "<<maxx<<"\n\nmin y :"<<miny<<" max y:  "<<maxy;
    return 0;
}
*/