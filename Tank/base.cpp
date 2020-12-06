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
    double YS_PI = 3.1415926;
    double r = 10;
    
//    glColor3ub(0, 0, 0);
//    glBegin(GL_QUADS);
//    glVertex2i(x - width / 2, y - height / 2);
//    glVertex2i(x - width / 2, y + height / 2);
//    glVertex2i(x + width / 2, y + height / 2);
//    glVertex2i(x + width / 2, y - height / 2);
//    glEnd();
    double L1=r * cos(36 * YS_PI / 180);
    double L2=r * sin(36 * YS_PI / 180);
    double L3=r * cos(72 * YS_PI / 180);
    double L4=r * sin(72 * YS_PI / 180);
    double L5=L2 * tan(72 * YS_PI / 180);
    double L6=L2 / cos(72 * YS_PI / 180);
    double L7=L6 * sin(54 * YS_PI / 180);
    double L8=L6 * cos(54 * YS_PI/180) + r;
    glBegin(GL_POLYGON);

    glVertex2f(x,y);
    glVertex2f(x+0.0f,y+L5+L1);
    glVertex2f(x+L2,y+L1);
    glVertex2f(x+L2+L6,y+L1);
    glVertex2f(x+L4,y-L3);
    glVertex2f(x+L7,y-L8);
    glVertex2f(x+0.0f,y-r);
    glVertex2f(x-L7,y-L8);
    glVertex2f(x-L4,y-L3);
    glVertex2f(x-L2-L6,y+L1);
    glVertex2f(x-L2,y+L1);
    glVertex2f(x+0.0f,y+L5+L1);
    glEnd();
}
