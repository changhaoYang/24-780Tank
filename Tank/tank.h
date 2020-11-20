#include "fssimplewindow.h"
#include "direction.h"

class Tank {
protected:
    int hp;
    int x, y;
    Direction facing;
    
public:
    Tank(const int x, const int y);
    void draw() const;
};

class MyTank: public Tank {
public:
    using Tank::Tank;
    
    void move(const Direction direction, const int speed);
};

class EnemyTank: public Tank {
public:
    using Tank::Tank;
    
    void move(const int speed);
};
