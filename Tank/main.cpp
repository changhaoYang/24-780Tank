#define GL_SILENCE_DEPRECATION

#include <stdio.h>
#include "tank.h"
#include "bullet.h"

int main() {
    FsOpenWindow(16, 16, 800, 600, 1);
    Bullet bullet = Bullet(400, 300, Direction::UP);
    while(FSKEY_NULL == FsInkey()) {
        FsPollDevice();
        glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
        
        bullet.draw();
        
        FsSwapBuffers();
        FsSleep(10);
    }
    return 0;
}
