#include "block_maze.h"
int level = 0;
Maze::Maze(void)
{
	
	int InitialBlocks1[LineNum][ColNum] = {
								 {0,0,0,0,0,   0,0,0,0,0,  0,0,0,0,0,  0,0,0,0,0},//0
								 {0,0,0,0,0,   0,0,0,0,0,  0,0,0,0,0,  0,0,0,0,0},//1
								 {0,0,0,0,0,   0,0,0,0,0,  0,0,0,0,0,  0,0,0,0,0},//2
								 {0,0,0,1,1,   0,0,1,1,1,  0,0,1,0,0,  1,1,1,0,0},//3
								 {0,0,0,1,0,   0,0,1,0,1,  0,0,1,0,0,  0,1,0,0,0},//4

								 {0,0,0,1,1,   0,0,1,1,1,  0,0,1,0,0,  0,1,0,0,0},//5
								 {0,0,0,0,1,   0,0,1,0,1,  0,0,1,0,0,  0,1,0,0,0},//6
								 {0,0,0,1,1,   0,0,1,0,1,  0,0,1,1,1,  0,1,0,0,0},//7
								 {2,2,0,0,0,   0,0,0,0,0,  0,0,0,0,0,  0,0,0,2,2},//8
								 {0,0,0,0,0,   0,0,0,0,0,  0,0,0,0,0,  0,0,0,0,0},//9

								 {0,1,1,1,0,   1,1,1,0,0,  0,0,1,1,1,  0,1,0,1,0},//10
								 {0,1,0,0,0,   0,1,0,0,2,  2,0,1,0,0,  0,1,0,1,0},//11
								 {0,1,1,1,2,   0,1,0,0,2,  2,0,1,1,1,  2,1,1,1,0},//12
								 {0,1,0,0,0,   0,1,0,0,0,  0,0,0,0,1,  0,1,0,1,0},//13
								 {0,1,0,0,0,   1,1,1,0,0,  0,0,1,1,1,  0,1,0,1,0},//14


								 {0,0,0,0,0,   0,0,0,0,0,  0,0,0,0,0,  0,0,0,0,0},//15
								 {0,1,1,1,0,   0,0,0,0,0,  0,0,0,0,0,  0,1,1,1,0},//15
								 {0,1,1,2,0,   0,0,0,1,1,  1,1,0,0,0,  0,2,1,1,0},//17
								 {0,1,1,1,0,   0,0,0,1,0,  0,1,0,0,0,  0,1,1,1,0},//18
								 {0,0,0,0,0,   0,0,0,1,0,  0,1,0,0,0,  0,0,0,0,0} };//19
	
	int InitialBlocks2[LineNum][ColNum] = {
								 {0,0,0,0,2,   0,0,0,0,0,  1,0,0,0,0,  0,0,0,0,0},//0
								 {0,1,0,0,2,   0,0,0,0,0,  1,0,0,0,0,  0,0,0,0,0},//1
								 {0,1,0,0,0,   1,0,0,0,1,  1,0,0,1,1,  0,0,1,0,0},//2
								 {0,0,0,1,0,   1,0,1,2,1,  1,0,0,1,1,  2,1,1,0,0},//3
								 {0,0,0,1,0,   1,2,1,0,0,  0,0,0,2,0,  0,0,0,0,0},//4

								 {1,1,1,1,1,   1,1,0,0,0,  0,0,0,1,0,  0,0,0,0,0},//5
								 {0,0,0,0,0,   0,0,0,0,0,  0,0,0,1,0,  0,0,0,0,0},//6
								 {0,1,2,2,0,   0,0,1,1,1,  0,0,2,1,0,  0,0,0,2,2},//7
								 {0,1,0,0,0,   0,0,2,0,0,  0,0,0,1,0,  0,0,1,0,0},//8
								 {0,0,0,0,0,   0,0,0,0,0,  0,0,0,2,0,  0,0,1,0,0},//9

								 {0,0,0,0,0,   1,0,0,0,0,  0,0,0,0,0,  1,0,0,0,0},//10
								 {0,0,1,0,0,   1,0,0,0,0,  0,0,0,0,0,  1,0,0,1,0},//11
								 {0,1,1,2,0,   1,0,0,1,0,  2,1,0,0,1,  1,0,0,1,0},//12
								 {0,0,0,0,0,   1,0,1,1,1,  1,1,1,0,0,  0,1,1,1,0},//13
								 {0,0,0,0,0,   2,0,0,1,1,  1,1,0,0,0,  0,0,0,0,0},//14

								 {0,0,1,0,0,   0,0,1,0,0,  0,0,0,1,0,  1,0,0,0,0},//15
								 {2,1,1,0,0,   0,0,0,0,0,  0,0,0,0,0,  0,2,0,0,0},//16
								 {2,0,1,0,0,   0,0,0,1,1,  1,1,0,0,0,  0,0,1,0,0},//17
								 {0,0,1,0,0,   0,0,2,1,0,  0,1,0,0,0,  0,0,0,1,0},//18
								 {2,0,1,0,0,   0,0,2,1,0,  0,1,0,0,0,  0,0,0,0,1} };//19
	
	int InitialBlocks3[LineNum][ColNum] = {
								 {0,2,2,0,0,   0,0,0,0,0,  0,0,0,0,0,  0,0,0,0,0},//0
								 {0,0,0,0,0,   0,0,0,0,1,  0,0,0,0,0,  0,0,0,0,0},//1
								 {2,0,0,0,0,   0,0,1,1,0,  0,0,0,0,0,  0,0,0,0,0},//2
								 {2,0,0,0,0,   1,1,1,1,1,  1,0,0,0,0,  0,0,0,0,0},//3
								 {2,0,0,0,0,   0,0,0,0,0,  1,0,0,0,0,  0,0,0,0,0},//4

								 {2,2,2,0,0,   0,0,0,0,0,  0,1,0,0,0,  0,0,0,0,0},//5
								 {0,0,0,0,0,   1,1,0,0,0,  0,1,0,0,0,  0,0,0,0,0},//6
								 {0,0,0,0,0,   1,0,0,1,0,  0,0,0,0,0,  0,0,0,0,1},//7
								 {0,0,0,0,0,   0,0,2,0,0,  0,0,0,2,0,  0,1,0,0,0},//8
								 {0,0,0,0,0,   0,0,0,0,0,  0,1,1,2,0,  1,2,1,0,2},//9

								 {0,0,0,0,0,   0,0,2,2,2,  0,0,1,0,0,  0,0,0,0,0},//10
								 {0,0,0,0,0,   1,1,1,1,0,  0,0,0,0,0,  0,0,1,0,0},//11
								 {0,1,0,0,0,   0,1,0,0,0,  0,0,0,0,0,  0,1,1,0,0},//12
								 {0,1,1,0,0,   0,0,1,0,0,  0,0,0,0,2,  1,1,1,0,0},//13
								 {0,1,1,2,1,   0,0,1,1,0,  0,0,0,0,0,  2,0,0,0,0},//14

								 {0,0,0,0,0,   0,0,0,0,0,  0,0,0,0,0,  0,0,0,1,1},//15
								 {0,1,1,0,0,   0,0,0,0,0,  0,0,0,0,0,  1,1,1,1,1},//16
								 {2,2,1,0,0,   0,0,0,1,1,  1,1,0,0,0,  0,1,0,1,1},//17
								 {0,1,1,1,0,   0,0,0,1,0,  0,1,0,0,0,  0,0,0,1,1},//18
								 {0,0,0,0,1,   0,0,0,1,0,  0,1,0,0,0,  0,0,2,0,0} };//19
		  
		 
	int(*p)[ColNum]; 
	p = InitialBlocks1;
	if (level == 2)
	{
		p = InitialBlocks2;
	}
	else if (level == 3)
	{
		p = InitialBlocks3;
	}
		 

	for (int i = 0; i < LineNum; i++)
	{
		for (int j = 0; j < ColNum; j++)
		{
			//blocks[i][j].bType = InitialBlocks[i][j];
			blocks[i][j].bType = p[i][j];
			if (blocks[i][j].bType == 1)
			{
				blocks[i][j].breakable = true;
			}
			else {
				blocks[i][j].breakable = false;
			}
			blocks[i][j].y = i;
			blocks[i][j].x = j;
		}
	}

}

void Maze::deleteBlock(int i, int j)
{
	if (0 <= i && i < ColNum && 0 <= j && j < LineNum)
	{
		if (blocks[i][j].breakable == true)
		{
			blocks[i][j].bType = 0;
			blocks[i][j].breakable = false;
		}	
	}
	else
	{
		std::cout << "i,j="<<i<<","<<j<<" i or j index out of range!" << std::endl;
	}

}
bool Maze::ifBulletDisappear(int i, int j)
{
	if (0 <= i && i < ColNum && 0 <= j && j < LineNum)
	{
		if (blocks[i][j].bType == 1|| blocks[i][j].bType == 2)
		{
			return true;
		}
		return false;
		
	}
	else
	{
		return true;
	}

}

bool Maze::ifWalkable(int i, int j)
{
	if (0 <= i && i < ColNum && 0 <= j && j < LineNum)
	{
		if (blocks[i][j].bType == 0) 
		{
			return true;
		}
		return false;
		
	}
	else
	{
		std::cout << "i,j=" << i << "," << j << " i or j index out of range!" << std::endl;
	}
    
    return false;
}
void Maze::Draw(void)const
{
	
	for (int i = 0; i < ColNum; i++)
	{
		for (int j = 0; j < LineNum; j++)
		{
			blocks[i][j].DrawBlock();

		}
	}
}
void block::DrawBlock(void)const
{
	if (bType==1)//draw wooden wall
	{
		//std::cout << x<<" "<<y <<std::endl;
		int a = size / 2;
		int b = size / 3;
		
		glColor3ub(139, 69, 19);
		glBegin(GL_QUADS);
		glVertex2i(x * size, y * size);
		glVertex2i(x*size + size, y * size);
		glVertex2i(x * size + size,  (y * size + size));
		glVertex2i(x * size, (y * size + size));
		glEnd();
		

		glColor3ub(0, 0, 0);
		glBegin(GL_LINES);
		glVertex2i(x * size + b, (y * size ));
		glVertex2i(x * size + b, (y * size + a));

		glVertex2i(x * size + 2*b,  (y * size));
		glVertex2i(x * size + 2*b, (y * size + a));

		glVertex2i(x * size + a, (y * size+a));
		glVertex2i(x * size + a, (y * size + size));

		glVertex2i(x * size , (y * size + a));
		glVertex2i(x * size + size,  (y * size + a));
		glEnd();

		glColor3ub(0, 0, 0);
		glBegin(GL_LINE_STRIP);
		glVertex2i(x * size,  y * size);
		glVertex2i(x * size + size,  y * size);
		glVertex2i(x * size + size,  (y * size + size));
		glVertex2i(x * size, (y * size + size));
		glVertex2i(x * size,  y * size);
		glEnd();

		
	}
	else if (bType == 2)
	{
		int a = size / 2;
		int b = size / 3;

		glColor3ub(169, 169, 169);
		glBegin(GL_QUADS);
		glVertex2i(x * size, y * size);
		glVertex2i(x * size + size, y * size);
		glVertex2i(x * size + size, (y * size + size));
		glVertex2i(x * size, (y * size + size));
		glEnd();


		glColor3ub(0, 0, 0);
		glBegin(GL_LINES);
		glVertex2i(x * size + b, (y * size));
		glVertex2i(x * size + b, (y * size + a));

		glVertex2i(x * size + 2 * b, (y * size));
		glVertex2i(x * size + 2 * b, (y * size + a));

		glVertex2i(x * size + a, (y * size + a));
		glVertex2i(x * size + a, (y * size + size));

		glVertex2i(x * size, (y * size + a));
		glVertex2i(x * size + size, (y * size + a));
		glEnd();

		glColor3ub(0, 0, 0);
		glBegin(GL_LINE_STRIP);
		glVertex2i(x * size, y * size);
		glVertex2i(x * size + size, y * size);
		glVertex2i(x * size + size, (y * size + size));
		glVertex2i(x * size, (y * size + size));
		glVertex2i(x * size, y * size);
		glEnd();

	}
	
}

