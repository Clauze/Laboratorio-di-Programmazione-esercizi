//Battistin Claudio 
#ifndef Maze_hpp
#define Maze_hpp
#include <string>
#include <iostream>
#include <fstream>
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

				}
				
				else if(myText[j] == 'E'){
					ye=i;
					xe=j;

				}
			}
			i++;
		}

	}


	printMaze();

	myfile.close();
	return true;
}

void Maze::printMaze(){

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
		
		if(int(matrix[ny][nx]) == 32){
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
		
		if(int(matrix[ny][nx]) == 32){
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
