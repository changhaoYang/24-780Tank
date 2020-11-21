#include <map>
#include "fssimplewindow.h"
#include "direction.h"
#include "block_maze.h"

const int fireFrequency = 5;
const int blockSize = 30;

class Tank {
protected:
    int hp;
    int x, y;
    Direction facing;
    Maze maze;
    
    bool isValidPosition(const int x, const int y);
    bool isValidStep(const int x, const int y, const Direction direction, const int speed);
    
public:
    Tank(const int x, const int y, const Maze &maze);
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
