#define GL_SILENCE_DEPRECATION

#include "bullet.h"

const int width = 4;
const int height = 10;

Bullet::Bullet() {

}

Bullet::Bullet(const int x, const int y, const Direction facing) {
    this->x = x;
    this->y = y;
    this->facing = facing;
}

int Bullet::getPosX() const {
    return x;
}

int Bullet::getPosY() const {
    return y;
}

void Bullet::move(const int speed) {
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
}

void Bullet::draw() const {
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    
    if (facing == Direction::UP || facing == Direction::DOWN) {
        glVertex2i(x - width / 2, y - height / 2);
        glVertex2i(x - width / 2, y + height / 2);
        glVertex2i(x + width / 2, y + height / 2);
        glVertex2i(x + width / 2, y - height / 2);
    } else {
        // Left and right
        glVertex2i(x - height / 2, y - width / 2);
        glVertex2i(x - height / 2, y + width / 2);
        glVertex2i(x + height / 2, y + width / 2);
        glVertex2i(x + height / 2, y - width / 2);
    }
    
    glEnd();
}

