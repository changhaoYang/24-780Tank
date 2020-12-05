#define GL_SILENCE_DEPRECATION

#include "base.h"

const int width = 20;
const int height = 20;

Base::Base() {

}

Base::Base(const int x, const int y) {
    this->x = x;
    this->y = y;
}

int Base::getPosX() const {
    return x;
}

int Base::getPosY() const {
    return y;
}

void Base::draw() const {
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(x - width / 2, y - height / 2);
    glVertex2i(x - width / 2, y + height / 2);
    glVertex2i(x + width / 2, y + height / 2);
    glVertex2i(x + width / 2, y - height / 2);
    glEnd();
}
