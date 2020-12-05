#pragma once
#include<stdlib.h>
#include<iostream>
//#include <vector>
#include"fssimplewindow.h"
#include "ysglfontdata.h"

#define BlockSize 30
#define LineNum 20
#define ColNum 20

class block
{
public:
	int x, y; //x:0~20  y:0~20
	int bType; //bType==1:woodenWall, 2:IronWall
	bool breakable;
	void DrawBlock(void)const;


};
class Maze
{
public:
	Maze() = default;
	Maze(const int l);//constructor, initialize maze according to level
	bool deleteBlock(int i, int j);//will delete a block if it is breakable 
	bool ifWalkable(int i, int j);
	bool ifBulletDisappear(int i, int j);
	void Draw(void) const;
private:
	block blocks[LineNum][ColNum];
	int level;
};

