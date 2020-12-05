#include "block_maze.h"
int level = 2;
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

bool Maze::deleteBlock(int i, int j)
{
	if (0 <= i && i < ColNum && 0 <= j && j < LineNum)
	{
		if (blocks[j][i].breakable == true)
		{
			blocks[j][i].bType = 0;
			blocks[j][i].breakable = false;
			return true;
		}	
		return false;
	}
	return true;

}
bool Maze::ifBulletDisappear(int i, int j)
{
	if (0 <= i && i < ColNum && 0 <= j && j < LineNum)
	{
		if (blocks[j][i].bType == 1|| blocks[j][i].bType == 2)
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
		if (blocks[j][i].bType == 0) 
		{
			return true;
		}
		return false;
		
	}
	else
	{
		return false;
	}

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
		int a = BlockSize / 2;
		int b = BlockSize / 3;
		
		glColor3ub(139, 69, 19);
		glBegin(GL_QUADS);
		glVertex2i(x * BlockSize, y * BlockSize);
		glVertex2i(x*BlockSize + BlockSize, y * BlockSize);
		glVertex2i(x * BlockSize + BlockSize,  (y * BlockSize + BlockSize));
		glVertex2i(x * BlockSize, (y * BlockSize + BlockSize));
		glEnd();
		

		glColor3ub(0, 0, 0);
		glBegin(GL_LINES);
		glVertex2i(x * BlockSize + b, (y * BlockSize ));
		glVertex2i(x * BlockSize + b, (y * BlockSize + a));

		glVertex2i(x * BlockSize + 2*b,  (y * BlockSize));
		glVertex2i(x * BlockSize + 2*b, (y * BlockSize + a));

		glVertex2i(x * BlockSize + a, (y * BlockSize+a));
		glVertex2i(x * BlockSize + a, (y * BlockSize + BlockSize));

		glVertex2i(x * BlockSize , (y * BlockSize + a));
		glVertex2i(x * BlockSize + BlockSize,  (y * BlockSize + a));
		glEnd();

		glColor3ub(0, 0, 0);
		glBegin(GL_LINE_STRIP);
		glVertex2i(x * BlockSize,  y * BlockSize);
		glVertex2i(x * BlockSize + BlockSize,  y * BlockSize);
		glVertex2i(x * BlockSize + BlockSize,  (y * BlockSize + BlockSize));
		glVertex2i(x * BlockSize, (y * BlockSize + BlockSize));
		glVertex2i(x * BlockSize,  y * BlockSize);
		glEnd();

        
        glRasterPos2d(x * BlockSize + BlockSize / 2, y * BlockSize + BlockSize / 2);
        YsGlDrawFontBitmap6x7("1");
		
	}
	else if (bType == 2)
	{
		int a = BlockSize / 2;
		int b = BlockSize / 3;

		glColor3ub(169, 169, 169);
		glBegin(GL_QUADS);
		glVertex2i(x * BlockSize, y * BlockSize);
		glVertex2i(x * BlockSize + BlockSize, y * BlockSize);
		glVertex2i(x * BlockSize + BlockSize, (y * BlockSize + BlockSize));
		glVertex2i(x * BlockSize, (y * BlockSize + BlockSize));
		glEnd();


		glColor3ub(0, 0, 0);
		glBegin(GL_LINES);
		glVertex2i(x * BlockSize + b, (y * BlockSize));
		glVertex2i(x * BlockSize + b, (y * BlockSize + a));

		glVertex2i(x * BlockSize + 2 * b, (y * BlockSize));
		glVertex2i(x * BlockSize + 2 * b, (y * BlockSize + a));

		glVertex2i(x * BlockSize + a, (y * BlockSize + a));
		glVertex2i(x * BlockSize + a, (y * BlockSize + BlockSize));

		glVertex2i(x * BlockSize, (y * BlockSize + a));
		glVertex2i(x * BlockSize + BlockSize, (y * BlockSize + a));
		glEnd();

		glColor3ub(0, 0, 0);
		glBegin(GL_LINE_STRIP);
		glVertex2i(x * BlockSize, y * BlockSize);
		glVertex2i(x * BlockSize + BlockSize, y * BlockSize);
		glVertex2i(x * BlockSize + BlockSize, (y * BlockSize + BlockSize));
		glVertex2i(x * BlockSize, (y * BlockSize + BlockSize));
		glVertex2i(x * BlockSize, y * BlockSize);
		glEnd();
        
        glRasterPos2d(x * BlockSize + BlockSize / 2, y * BlockSize + BlockSize / 2);
        YsGlDrawFontBitmap6x7("2");

	}
    else {
        glRasterPos2d(x * BlockSize + BlockSize / 2, y * BlockSize + BlockSize / 2);
        YsGlDrawFontBitmap6x7("0");
    }
	
}

