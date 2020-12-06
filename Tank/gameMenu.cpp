#define GL_SILENCE_DEPRECATION
//
//  gameMenu.cpp
//  group_tankwar
//
//  Created by felicity 子君 on 12/4/20.
//
#include "gameMenu.h"
#include <string>
#include <time.h>
#include <stdlib.h>

gameMenu::gameMenu(int w, int h) {
    
    width = w;
    
    height = h;
    
}

void gameMenu::drawRectangle(double x1, double x2, double y1, double y2) {
    glBegin(GL_QUADS);
    glVertex2d(x1, y1);
    glVertex2d(x2, y1);
    glVertex2d(x2, y2);
    glVertex2d(x1, y2);
    glEnd();
}
void gameMenu::flash(bool selected) //alternates between grey and orange
{
    //if a button is selected
    if (!selected)
        glColor3ub(128, 128, 128);
    else
        glColor3ub(255, 128, 0);
}

void gameMenu::showText(const char *text, int posX, int posY, int r, int g, int b) {
    glColor3ub(r, g, b);
    glRasterPos2i(posX, posY);  // sets position
    YsGlDrawFontBitmap6x10(text);

}
void gameMenu::drawButtons( const char *text, bool selected, double x1, double y1, int w, int h) {
    
    flash(selected);
    drawRectangle(x1, x1 + w, y1, y1 - h);
    showText(text,x1 + w/6,y1 - 20,255,255,255);
    
}

void gameMenu::drawMainMenu(bool first) {
//    if (first)
//            flash(loopcnt);
//    else
//        glColor3ub(128, 128, 128);
//
//    glClearColor(0,0,0,0);
//    bool selected = false;
    glColor3ub(255, 128, 0);
    glRasterPos2i(width / 3, height / 4);
    YsGlDrawFontBitmap32x48("Tank War");
//    drawButtons("  start game  ", selected, 150, 300, 100, 50);
    
    drawButtons("select level ", first, 200, 300, 100, 50);
    drawButtons("    quit    ", !first, 500, 300, 100, 50);
}
void gameMenu::drawSelectLevel(int idx) {
//    glClearColor(0,0,0,0);
//    bool selected = false;
    string level{" level "};
    for (int i = 1; i < 4; i++){
        drawButtons((level + to_string(i)).c_str(), idx == i, 350, 200 + (i - 1) * 150, 100, 50);
    }
//    drawButtons("  level 1", selected, 200, 200, 100, 50);
//    drawButtons("  level 2", selected, 200, 350, 100, 50);
//    drawButtons("  level 3", selected, 200, 500, 100, 50);
//    drawButtons("back to menu", selected, 500, 350, 100, 50);
}

void gameMenu::drawScore(int score, int lives) {
    bool first = false;
    drawButtons(" Score: ",first, 620, 50, 80, 50);
    drawButtons(" lives: ",first, 620, 150, 80, 50);
    drawButtons(to_string(score).c_str(),first, 720, 50, 50, 50);
    drawButtons(to_string(lives).c_str(),first, 720, 150, 50, 50);
    
}

class Firework {
private:
    int color;
    double x,y;
public:
    Firework();
    Firework(double x, double y);
    void Blink();
    void Drawfirework();
    void Fall(int wind);
};

Firework::Firework() {
    x = 0;
    y = 0;
    color = 0;
}
Firework::Firework(double newx, double newy) {
    x = newx;
    y = newy;
}


void Firework::Blink(){
    int color = rand() % 4 + 1;
    switch (color) {
        case 1:glColor3ub(176, 224, 230);//grey blue
            break;
        case 2:glColor3ub(192, 192, 192);//sliver
            break;
        case 3:glColor3ub(245, 222, 179);//light yellow
            break;
        case 4:glColor3ub(128, 128, 128);//gray
            break;
    }
}

void Firework::Drawfirework() {
    Blink();
    glBegin(GL_POLYGON);
    
    glVertex2f(x - 5,y - 3.75);
    glVertex2f(x - 7.5,y - 15);
    glVertex2f(x - 3.5,y - 14);
    glVertex2f(x,y - 20);
    glVertex2f(x + 3.5,y - 14);
    glVertex2f(x + 7.5,y - 15);
    glVertex2f(x + 5,y - 3.75);

    glEnd();
}

void Firework::Fall(int wind) {
    int v = rand() % 500 + 1;
    y += v;
    if (y >= 500) {
        y = 0;
        x = rand() % 500 + 1;
    }
    x += wind;
   
}

Firework firework[50];

void gameMenu::drawWin() {
    for(int i = 0; i < 50; i++) {
        firework[i] = Firework(rand() % 500 + 1,rand() % 500 + 1);
    }
    for (int j = 0; j < 10; j++) {
        for (int i = 0 ; i < 5; i++) {
            firework[j * 10 + i].Drawfirework();
            firework[j * 10 + i].Fall(1);
        }
    }
    
    
}




