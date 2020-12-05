#include "game.h"

static const int UPDATE_TIME = 20;
int main(void) {
	int x[]{ 500, 600, 700 };
	int y[]{ 50, 100, 150 };
	Direction dir[]{ Direction::DOWN, Direction::DOWN, Direction::DOWN };
	Base base = Base(400, 500);
	Maze maze;
	GameControl gameControl = GameControl(x, y, dir, maze, base);

	FsOpenWindow(16, 16, 800, 600, 1);
	//glClearColor(0, 0, 0, 0);
	int key = FsInkey();
	bool win = true;

	while (key != FSKEY_ESC) {
		key = FsInkey();
		FsPollDevice();
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

		gameControl.Draw();
		gameControl.UpdatePosition();
		gameControl.UpdateAllBullet(win);
		/*gameControl.ProduceTank();
		gameControl.increaseTime();*/

		FsSwapBuffers();
		FsSleep(UPDATE_TIME);
	}
}
