#include "game.h"
#include <iostream>

GameControl::GameControl(int x[], int y[], Direction dir[], Maze &chosenMaze, Base chosenBase) {
	appearanceX = x;
	appearanceY = y;
	appearanceDir = dir;
	maze = chosenMaze;
	base = chosenBase;

	Init();
}

void GameControl::Init() {
	myTank = new MyTank(RESPAWN_X, RESPAWN_Y, &maze);
	ProduceTank();

	score = 0;
	lives = 3;
	appearanceCnt = 0;
	timeCount = 0;
}

/** 
 * Respawn player's tank
 * @return return false if player has 0 life
 */
bool GameControl::Respawn() {
	if (lives == 0) {
		return false;
	}

	lives--;
	myTank =new  MyTank(RESPAWN_X, RESPAWN_Y, &maze);
	return true;
}

/**
 * Update all elements' position
 */
void GameControl::UpdatePosition() {
	for (auto &enemyTank : enemyTanks) {
		enemyTank.move(TANK_SPEED);
		enemyTank.getBullet().move(BULLET_SPEED);
	}
	myTank->getBullet().move(BULLET_SPEED);
}

/**
 * Move player's tank
 * @param dir Player's tank's moving direction
 */
void GameControl::MoveTank(Direction dir) {
	myTank->move(dir, TANK_SPEED * 3);
}

/**
 * Draw all elements
 */
void GameControl::Draw() {
	for (auto enemyTank : enemyTanks) {
		enemyTank.draw();
		if (enemyTank.isBullet()) {
			enemyTank.getBullet().draw();
		}
	}
    if (myTank->isBullet()) {
      myTank->getBullet().draw();
     }
	maze.Draw();
	myTank->draw();
}

/**
 * Update all bullets' existence state
 */
void GameControl::UpdateAllBullet(bool &win) {
	for (auto i = 0; i < enemyTanks.size(); i++) {
		if (!enemyTanks[i].isBullet()) {
			continue;
		}

		Bullet bullet = enemyTanks[i].getBullet();
//		std::cout << "the pos of bullet: " << bullet.getPosX() << std::endl;
		enemyTanks[i].moveBullet(BULLET_SPEED);
		if (CheckMyTankHit(bullet)) {
			enemyTanks[i].disBullet();
			myTank->decreaseHp();
            std::cout << "I was hit!" << std::endl;
            std::cout << myTank->getHp() << std::endl;
		}
		else if (CheckBaseHit(bullet, base)) {
			win = false;
			return;
		}
		else if(DeleteBlock(bullet)){
			enemyTanks[i].disBullet();
            std::cout << "Block deleted!" << std::endl;
		}
	}
	if (myTank->getHp() == 0) {
		if (!Respawn()) {
			win = false;
			return;
		}
	}

    for (auto j = 0; j < enemyTanks.size(); j++) {
      myTank->moveBullet(BULLET_SPEED);
      if (CheckEnemyTankHit(myTank->getBullet(), enemyTanks[j])) {
       myTank->disBullet();
       enemyTanks[j].decreaseHp();
       if (enemyTanks[j].getHp() == 0) {
        DeleteTank(j);
       }
       break;
      }
     }

     if (myTank->isBullet() && DeleteBlock(myTank->getBullet())) {
      myTank->disBullet();
     }

	for (auto &enemyTank : enemyTanks) {
		Fire(enemyTank);
	}
	
}

void GameControl::Fire(Tank &tank) {
	tank.increaseCount();
	if (tank.getCount() == 0) {
		tank.fire();
	}
}

void GameControl::myFire() {
//	Fire(*myTank);
    if (!myTank->isBullet()) {
      myTank->fire();
     }
}

/**
 * Check whether bullet hits the tank
 */
bool GameControl::CheckMyTankHit(Bullet bullet) {
	if (bullet.getPosX() <= myTank->getPosX() + 7 && bullet.getPosX() >= myTank->getPosX() - 7 &&
		bullet.getPosY() == myTank->getPosY() + 7 && bullet.getPosY() == myTank->getPosY() - 7) {
		return true;
	}
	return false;
}

bool GameControl::CheckEnemyTankHit(Bullet bullet, EnemyTank enemyTank) {
	if (bullet.getPosX() <= enemyTank.getPosX()+7 && bullet.getPosX() >= enemyTank.getPosX()-7 &&
		bullet.getPosY() == enemyTank.getPosY()+7 && bullet.getPosY() == enemyTank.getPosY()-7) {
		return true;
	}
	return false;
}

/**
 * Check whether bullet hits the base
 */
bool GameControl::CheckBaseHit(Bullet bullet, Base base) {
	if (bullet.getPosX() <= base.getPosX()+GRID_SIZE/2 && bullet.getPosX() >= base.getPosX() - GRID_SIZE / 2 &&
		bullet.getPosY() <= base.getPosY() + GRID_SIZE / 2 && bullet.getPosY() <= base.getPosY() - GRID_SIZE / 2) {
		return true;
	}
	return false;
}

/**
 * Delete tanks who have 0 hp
 */
void GameControl::DeleteTank(int index) {
	enemyTanks.erase(enemyTanks.begin()+index);
}

/**
 * Delete blocks that have the same position with bullets
 */
bool GameControl::DeleteBlock(Bullet bullet) {
	int i = bullet.getPosX() / GRID_SIZE;
	int j = bullet.getPosY() / GRID_SIZE;
	bool output = maze.ifBulletDisappear(i, j);
	maze.deleteBlock(i, j);
	return output;
}

/**
 * Increase the score
 */
void GameControl::UpdateScore() {
	score++;
}

void GameControl::ProduceTank() {
	if (enemyTanks.size() > TANKS_MAX) {
		return;
	}
	if (timeCount == 0) {
		
		if (appearanceCnt == 3) {
			appearanceCnt = 0;
		}
		EnemyTank enemyTank = EnemyTank(appearanceX[appearanceCnt],
			appearanceY[appearanceCnt], &maze);
		enemyTanks.push_back(enemyTank);
		appearanceCnt++;
	}
}

void GameControl::increaseTime() {
	timeCount++;
	if (timeCount == 500) {
		timeCount = 0;
	}
}

int GameControl::GetLives() {
	return lives;
}

int GameControl::GetScore() {
	return score;
}






