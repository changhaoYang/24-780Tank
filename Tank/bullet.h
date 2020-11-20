#include "fssimplewindow.h"

enum class Direction { UP, DOWN, LEFT, RIGHT };

class Bullet {
private:
    int x, y;
    Direction facing;
    
public:
    Bullet(const int x, const int y, const Direction facing);
    int getPosX() const;
    int getPosY() const;
    void move(int speed);
    void draw() const;
};
