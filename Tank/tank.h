#include "fssimplewindow.h"
#include "direction.h"
#include <map>

const int fireFrequency = 5;

class Tank {
protected:
    int hp;
    int x, y;
    Direction facing;
    
public:
    Tank(const int x, const int y);
    void draw() const;
    void decreaseHp();
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
