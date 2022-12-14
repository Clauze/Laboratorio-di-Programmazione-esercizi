#ifndef Maze_h
#define Maze_h
#include <string>
#include <iostream>
using namespace std;
constexpr int matrixDim=9;

class Maze{
private:
	char matrix[matrixDim][matrixDim];
	int xs,ys,xe,ye;
	string file;
	bool fillMatrix();
public:
	
	Maze(string f);
	void printMaze();
	int getXs()const;
	int getYs()const;
	int getXe()const;
	int getYe()const;
	char getValue(int x,int y)const;
	int setSSpos(int nx,int ny);
	int setSRightPos(int nx,int ny);
};

#include "Maze.hpp"
#endif