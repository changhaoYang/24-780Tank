#define GL_SILENCE_DEPRECATION

#include <stdio.h>
#include "tank.h"
#include "bullet.h"
#include "base.h"

int main() {
    FsOpenWindow(16, 16, 800, 600, 1);
    Bullet bullet = Bullet(400, 300, Direction::UP);
    Base base = Base(400, 585);
    
    MyTank mytank1 = MyTank(200, 300);
    MyTank mytank2 = MyTank(200, 400);
    mytank2.move(Direction::DOWN, 3);
    MyTank mytank3 = MyTank(300, 300);
    mytank3.move(Direction::LEFT, 3);
    MyTank mytank4 = MyTank(300, 400);
    mytank4.move(Direction::RIGHT, 3);
    
    EnemyTank enemyTank = EnemyTank(400, 400);
    
    while(FSKEY_NULL == FsInkey()) {
        FsPollDevice();
        glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
        
        bullet.draw();
        base.draw();
        
        mytank1.draw();
        mytank2.draw();
        mytank3.draw();
        mytank4.draw();
        
        enemyTank.draw();
        enemyTank.move(3);
        
        FsSwapBuffers();
        FsSleep(10);
    }
    return 0;
}
