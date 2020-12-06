#define GL_SILENCE_DEPRECATION

#include "game.h"
#include "gameMenu.h"
#include <iostream>

static const int UPDATE_TIME = 20;
int main(void) {
    gameMenu gm(800, 600);
    FsOpenWindow(16, 16, 800, 600, 1);
    int first_end = false;
    bool first = true;
    int key = FsInkey();
    while(!first_end) {
        FsPollDevice();
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
        
        gm.drawMainMenu(first);
        key = FsInkey();
        
//        FsPollDevice();
//        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
        switch(key) {
            case FSKEY_ENTER:
                first_end = true;
                break;
            case FSKEY_RIGHT:
            case FSKEY_LEFT:
                first = !first;
                break;
        }
        
        FsSwapBuffers();
        FsSleep(UPDATE_TIME);
        
    }
    if(!first) {
        return 0;
    }
    
    int idx = 1;
    int second_end = false;
    while(!second_end) {
        key = FsInkey();
        FsPollDevice();
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
        gm.drawSelectLevel(idx);
        switch(key) {
            case FSKEY_ENTER:
                second_end = true;
                break;
            case FSKEY_UP:
                idx--;
                if (idx == 0) idx = 3;
                break;
            case FSKEY_DOWN:
                idx++;
                if (idx == 4) idx = 1;
                break;
        }
        FsSwapBuffers();
        FsSleep(UPDATE_TIME);
        
    }
    Maze maze(idx);
    
    //start game
    int x[]{ 300, 50, 500 };
    int y[]{ 50, 100, 150 };
    Direction dir[]{ Direction::DOWN, Direction::DOWN, Direction::DOWN };
    Base base = Base(300, 580);
    
    GameControl gameControl = GameControl(x, y, dir, maze, base);

    
    //glClearColor(0, 0, 0, 0);
    key = FsInkey();
    bool win = false;
    bool baseAlive = true;
    int threshold = 1;

    while (key != FSKEY_ESC) {
        key = FsInkey();
        FsPollDevice();
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        gameControl.Draw();
        gameControl.UpdatePosition();
        gameControl.UpdateAllBullet(baseAlive);
        gameControl.ProduceTank();
        gameControl.increaseTime();
        switch(key) {
            case FSKEY_SPACE:
                gameControl.myFire();
                break;
            case FSKEY_UP:
                gameControl.MoveTank(Direction::UP);
                break;
            case FSKEY_DOWN:
                gameControl.MoveTank(Direction::DOWN);
                break;
            case FSKEY_LEFT:
                gameControl.MoveTank(Direction::LEFT);
                break;
            case FSKEY_RIGHT:
                gameControl.MoveTank(Direction::RIGHT);
                break;
        }
        gm.drawScore(gameControl.GetScore(),gameControl.GetLives());
        
        if (gameControl.GetScore() >= threshold) {
            win = true;
            break;
        }
        if (gameControl.GetLives() == 0) {
            break;
        }
        
        if (!baseAlive) {
            std::cout << "Base destroyed!" << std::endl;
            break;
        }

        FsSwapBuffers();
        FsSleep(UPDATE_TIME);
    }
    
    
    if (win) {
        while(key != FSKEY_ESC){
            key = FsInkey();
            FsPollDevice();
            glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
            
            gm.drawWin();
            
            FsSwapBuffers();
            FsSleep(UPDATE_TIME);
        }
    } else {
        // TODO: lose display
    }
}
