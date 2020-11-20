#include "fssimplewindow.h"

class Tank {
private:
    int hp;
    int x, y;
    
public:
    void draw() const;
    void move();
};

class MyTank: public Tank {
    
};

class EnemyTank: public Tank {
    
};
