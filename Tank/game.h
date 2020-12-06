#include<iostream>
#include <stdio.h>
#include<time.h>
#include<vector>
#include "fssimplewindow.h"
#include <stdlib.h>
#include "base.h"
#include "bullet.h"
#include "tank.h"
#include "yssimplesound.h"

static const int GRID_SIZE = 30;
static const int RESPAWN_X = 200;
static const int RESPAWN_Y = 500;
static const int TANK_SPEED = 2;
static const int BULLET_SPEED = 4;
static const int TANKS_MAX = 6;

class GameControl {
public:
	GameControl(int x[], int y[], Direction dir[], Maze &chosenMaze, Base chosenBase);
	void Init();
	bool Respawn();
	void UpdatePosition();
	void MoveTank(Direction dir);
	void Draw();
	void Fire(Tank &tank);
	void increaseTime();
	void UpdateAllBullet(bool &win);
	void ProduceTank();
	void myFire();
	int GetScore();
	int GetLives();
	void PlayBGM();
	void PlaySound();
	void PrintResult();

private:
	bool CheckMyTankHit(Bullet bullet);
	bool CheckEnemyTankHit(Bullet bullet, EnemyTank enemyTank);
	bool CheckBaseHit(Bullet bullet, Base base);
	void DeleteTank(int index);
	bool DeleteBlock(Bullet bullet);
	void UpdateScore();

	int score;
	MyTank *myTank;
	std::vector<EnemyTank> enemyTanks;
	Maze maze;
	int lives;
	int *appearanceX;
	int *appearanceY;
	int appearanceCnt;
	Direction *appearanceDir;
	Base base;
	int timeCount;
};
