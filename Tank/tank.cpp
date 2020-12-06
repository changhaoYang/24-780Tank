#define GL_SILENCE_DEPRECATION

#include "tank.h"
#include <iostream>

Direction directions[4] = {
    Direction::UP, Direction::RIGHT, Direction::LEFT, Direction::DOWN
};

Tank::Tank(const int x, const int y, Maze* maze) {
	is_bullet_ = false;
    hp = 1;
	fireCount = 0;
    this->x = x;
    this->y = y;
    this->maze = maze;
    this->facing = Direction::UP;
}

void Tank::increaseCount() {
	fireCount++;
	if (fireCount == 200) {
		fireCount = 0;
	}
}

void Tank::decreaseHp() {
    --hp;
}

void drawVerticalTank(const int x, const int y, const bool isUp) {
    // Draw tank tracks
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(x - 8, y - 5);
    glVertex2i(x - 5, y - 5);
    glVertex2i(x - 5, y + 5);
    glVertex2i(x - 8, y + 5);
    glEnd();
    
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(x + 5, y - 5);
    glVertex2i(x + 8, y - 5);
    glVertex2i(x + 8, y + 5);
    glVertex2i(x + 5, y + 5);
    glEnd();
    
    // Draw tank barrel
    glColor3ub(0, 0, 255);
    glBegin(GL_LINES);
    if (isUp) {
        glVertex2i(x, y - 5);
        glVertex2i(x, y - 10);
    } else {
        glVertex2i(x, y + 5);
        glVertex2i(x, y + 10);
    }
    glEnd();
}

void drawHorizontalTank(const int x, const int y, const bool isLeft) {
    // Draw tank tracks
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(x - 5, y - 8);
    glVertex2i(x + 5, y - 8);
    glVertex2i(x + 5, y - 5);
    glVertex2i(x - 5, y - 5);
    glEnd();
    
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(x - 5, y + 5);
    glVertex2i(x + 5, y + 5);
    glVertex2i(x + 5, y + 8);
    glVertex2i(x - 5, y + 8);
    glEnd();
    
    // Draw tank barrel
    glColor3ub(0, 0, 255);
    glBegin(GL_LINES);
    if (isLeft) {
        glVertex2i(x - 5, y);
        glVertex2i(x - 10, y);
    } else {
        glVertex2i(x + 5, y);
        glVertex2i(x + 10, y);
    }
    glEnd();
}

void Tank::draw() const {
    // Draw tank base
    if (isEnemy) {
        glColor3ub(194, 126, 217);
    } else {
        glColor3ub(0, 255, 0);
    }
    
    glBegin(GL_QUADS);
    glVertex2i(x - 5, y - 5);
    glVertex2i(x + 5, y - 5);
    glVertex2i(x + 5, y + 5);
    glVertex2i(x - 5, y + 5);
    glEnd();
    
    switch (facing) {
        case Direction::UP:
            drawVerticalTank(x, y, true);
            break;
        case Direction::DOWN:
            drawVerticalTank(x, y, false);
            break;
        case Direction::LEFT:
            drawHorizontalTank(x, y, true);
            break;
        case Direction::RIGHT:
            drawHorizontalTank(x, y, false);
            break;
    }
}

MyTank::MyTank(const int x, const int y, Maze* maze) : Tank(x, y, maze) {
    this->isEnemy = false;
}

EnemyTank::EnemyTank(const int x, const int y, Maze* maze) : Tank(x, y, maze) {
    this->isEnemy = true;
}

void MyTank::move(const Direction direction, const int speed) {
    switch (direction) {
        case Direction::UP:
            if (isValidStep(x, y, Direction::UP, speed + 7)) {
                y -= speed;
                facing = Direction::UP;
            }
            break;
        case Direction::DOWN:
            if (isValidStep(x, y, Direction::DOWN, speed + 7)) {
                y += speed;
                facing = Direction::DOWN;
            }
            break;
        case Direction::LEFT:
            if (isValidStep(x, y, Direction::LEFT, speed + 7)) {
                x -= speed;
                facing = Direction::LEFT;
            }
            break;
        case Direction::RIGHT:
            if (isValidStep(x, y, Direction::RIGHT, speed + 7)) {
                x += speed;
                facing = Direction::RIGHT;
            }
            break;
    }
}

bool Tank::isValidPosition(const int x, const int y) {
    int blockXIndex = x / blockSize;
    int blockYIndex = y / blockSize;
    return x > 0 && x < 800 && y > 0 && y < 600 && maze->ifWalkable(blockYIndex, blockXIndex);
}

bool Tank::isValidStep(const int x, const int y, const Direction direction, const int speed) {
    int nextX, nextY;
    switch (direction) {
        case Direction::UP:
            nextY = y - speed;
            return isValidPosition(x, nextY);
        case Direction::DOWN:
            nextY = y + speed;
            return isValidPosition(x, nextY);
        case Direction::LEFT:
            nextX = x - speed;
            return isValidPosition(nextX, y);
        default:
            nextX = x + speed;
            return isValidPosition(nextX, y);
    }
}

void EnemyTank::move(const int speed) {
    if (isValidStep(x, y, facing, speed + 7)) {
        switch (facing) {
            case Direction::UP:
                y -= speed;
                break;
            case Direction::DOWN:
                y += speed;
                break;
            case Direction::LEFT:
                x -= speed;
                break;
            case Direction::RIGHT:
                x += speed;
                break;
        }
    } else {
        int result = rand() % 4;
        facing = directions[result];
    }
}

void Tank::fire() {
	bullet = Bullet(x, y, facing);
	is_bullet_ = true;
}

void Tank::disBullet() {
	is_bullet_ = false;
}

void Tank::moveBullet(const int speed) {
	bullet.move(speed);
}

bool Tank::isBullet() {
	return is_bullet_;
}

Bullet Tank::getBullet() {
	return bullet;
}

int Tank::getPosX() {
	return x;
}

int Tank::getPosY() {
	return y;
}

int Tank::getHp() {
	return hp;
}

Direction Tank::getDir() {
	return facing;
}

int Tank::getCount() {
	return fireCount;
}
