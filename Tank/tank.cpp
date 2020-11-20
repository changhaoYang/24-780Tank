#define GL_SILENCE_DEPRECATION

#include "tank.h"

Tank::Tank(const int x, const int y) {
    this->hp = 3;
    this->x = x;
    this->y = y;
    this->facing = Direction::UP;
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
    glColor3ub(0, 255, 0);
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

void MyTank::move(const Direction direction, const int speed) {
    switch (direction) {
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
