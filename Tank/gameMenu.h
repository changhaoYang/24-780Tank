#include <iostream>
#include <fstream>
#include <string>
#include "fssimplewindow.h"
#include "ysglfontdata.h"

using namespace std;

class gameMenu {
private:
    int width, height, cnt;
    double x, y;
    char nickname[20];
//    gameContorller gc;
//    Maze mz;
public:
    gameMenu(int w, int h);
    void drawRectangle(double x1, double x2, double y1, double y2);
    void drawScreen();
    void drawButtons(const char *text, bool selected, double x1, double y1, int w, int h);
    void showText(const char *text, int posX, int posY, int r, int g, int b);
    void flash(bool selected);
    void showNickname(int pos, bool ready, bool pve, bool secondInput);
    void saveNickname(int &pos, bool &secondInput, bool pve, bool &terminate, string &name1, string &name2);
    void loadNickname(int &pos, bool &ready, bool &secondInput, bool pve, bool &terminate, string &name1, string &name2);
    void drawMainMenu(bool first);
    void drawSelectLevel(int idx);
    void switchUI();
    void drawScore(int score, int lives);
    void drawWin();
};

