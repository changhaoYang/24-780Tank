#define GL_SILENCE_DEPRECATION

#include <stdio.h>
#include "tank.h"
#include "bullet.h"
#include "base.h"

int main() {
    FsOpenWindow(16, 16, 800, 600, 1);
    Bullet bullet = Bullet(400, 300, Direction::UP);
    Base base = Base(300, 585);
    
    Maze maze = Maze();
    
    MyTank mytank1 = MyTank(200, 300, maze);
    MyTank mytank2 = MyTank(200, 400, maze);
    mytank2.move(Direction::DOWN, 3);
    MyTank mytank3 = MyTank(300, 360, maze);
    mytank3.move(Direction::LEFT, 3);
    MyTank mytank4 = MyTank(300, 400, maze);
    mytank4.move(Direction::RIGHT, 3);
    
    EnemyTank enemyTank1 = EnemyTank(80, 100, maze);
    EnemyTank enemyTank2 = EnemyTank(350, 280, maze);
    EnemyTank enemyTank3 = EnemyTank(250, 300, maze);
    EnemyTank enemyTank4 = EnemyTank(450, 400, maze);
    
    while(FSKEY_ESC != FsInkey()) {
        FsPollDevice();
        glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
        
        maze.Draw();
        
//        bullet.draw();
//        base.draw();
        
//        mytank1.draw();
//        mytank2.draw();
//        mytank3.draw();
//        mytank4.draw();
        
        enemyTank1.draw();
        enemyTank1.move(3);
        enemyTank2.draw();
        enemyTank2.move(3);
        enemyTank3.draw();
        enemyTank3.move(3);
        enemyTank4.draw();
        enemyTank4.move(3);
        
        FsSwapBuffers();
        FsSleep(25);
    }
    return 0;
}
