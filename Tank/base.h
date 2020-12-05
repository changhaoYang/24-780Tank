#pragma once
#include "fssimplewindow.h"

class Base {
private:
    int x, y;
    
public:
	Base();
    Base(const int x, const int y);
    int getPosX() const;
    int getPosY() const;
    void draw() const;
};
