#define GL_SILENCE_DEPRECATION

#include "tank.h"

Tank::Tank(const int x, const int y) {
    this->hp = 3;
    this->x = x;
    this->y = y;
    this->facing = Direction::UP;
}

void Tank::draw() const {
    glColor3ub(0, 255, 0);
    glBegin(GL_QUADS);
    glVertex2i(x - 5, y - 5);
    glVertex2i(x + 5, y - 5);
    glVertex2i(x + 5, y + 5);
    glVertex2i(x - 5, y + 5);
    glEnd();
    
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
    
    glColor3ub(0, 0, 255);
    glBegin(GL_LINES);
    glVertex2i(x, y - 5);
    glVertex2i(x, y - 10);
    glEnd();
}

void MyTank::move(const Direction direction, const int speed) {
    switch (facing) {
        case Direction::UP:
            y -= speed;
            facing = Direction::UP;
            break;
        case Direction::DOWN:
            y += speed;
            facing = Direction::DOWN;
            break;
        case Direction::LEFT:
            x -= speed;
            facing = Direction::LEFT;
            break;
        case Direction::RIGHT:
            x += speed;
            facing = Direction::RIGHT;
            break;
    }
}
