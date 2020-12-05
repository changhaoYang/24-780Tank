#pragma once
#include <map>
#include "fssimplewindow.h"
#include "direction.h"
#include "block_maze.h"
#include "bullet.h"

const int blockSize = 30;

class Tank {
protected:
    int hp;
    int x, y;
	int fireCount;
    Direction facing;
    Maze* maze;
	Bullet bullet;
	bool is_bullet_;
    
    bool isValidPosition(const int x, const int y);
    bool isValidStep(const int x, const int y, const Direction direction, const int speed);
    
public:
    Tank(const int x, const int y, Maze* maze);
    void draw() const;
    void decreaseHp();
	void increaseCount();
	void moveBullet(const int speed);
	int getPosX();
	int getPosY();
	int getHp();
	Direction getDir();
	int getCount();
	void fire();
	bool isBullet();
	Bullet getBullet();
	void disBullet();
};

class MyTank: public Tank {
public:
    using Tank::Tank;
    
    void move(const Direction direction, const int speed);
};

class EnemyTank: public Tank {
private:
    int steps = 0;
public:
    using Tank::Tank;
    
    void move(const int speed);
};
