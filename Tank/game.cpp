#include "game.h"
#include <iostream>

GameControl::GameControl(int x[], int y[], Direction dir[], Maze &chosenMaze, Base chosenBase) {
	appearanceX = x;
	appearanceY = y;
	appearanceDir = dir;
	score = 0;
	lives = 3;
	appearanceCnt = 0;
	maze = chosenMaze;
	base = chosenBase;

	Init();
}

void GameControl::Init() {
	EnemyTank enemyTank = EnemyTank(appearanceX[0], appearanceY[0], &maze);
	myTank = new MyTank(RESPAWN_X, RESPAWN_Y, &maze);
	enemyTanks.push_back(enemyTank);
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
	for (auto &enemyBullet : enemyBullets) {
		enemyBullet.move(BULLET_SPEED);
		
	}
	for (auto &enemyTank : enemyTanks) {
		enemyTank.move(TANK_SPEED);
	}
	for (auto &myBullet : myBullets) {
		myBullet.move(BULLET_SPEED);
	}
}

/**
 * Move player's tank
 * @param dir Player's tank's moving direction
 */
void GameControl::MoveTank(Direction dir) {
	myTank->move(dir, TANK_SPEED);
}

/**
 * Draw all elements
 */
void GameControl::Draw() {
	for (auto enemyBullet : enemyBullets) {
		enemyBullet.draw();
//		std::cout << "the pos of x: " << enemyBullet.getPosX() << "the pos of y: " << enemyBullet.getPosY() << std::endl;
	}
	for (auto enemyTank : enemyTanks) {
		enemyTank.draw();
	}
	for (auto myBullet : myBullets) {
		myBullet.draw();
	}
	maze.Draw();
	myTank->draw();
}

/**
 * Update all bullets' existence state
 */
void GameControl::UpdateAllBullet(bool &win) {
	for (auto i = 0; i < enemyBullets.size(); i++) {
		if (CheckMyTankHit(enemyBullets[i])) {
			DeleteEnemyBullet(i);
			myTank->decreaseHp();
			i--;
		}
		else if (CheckBaseHit(enemyBullets[i], base)) {
			win = false;
			return;
		}
		else if(DeleteBlock(enemyBullets[i])){
            std::cout << "Delete block" << std::endl;
			DeleteEnemyBullet(i);
			i--;
		}
	}
	if (myTank->getHp() == 0) {
		if (!Respawn()) {
			win = false;
			return;
		}
	}

	for (auto i = 0; i < myBullets.size(); i++) {
		auto tanks_size = enemyTanks.size();
		for (auto j = 0; j < tanks_size; j++) {
			if (CheckEnemyTankHit(myBullets[j], enemyTanks[j])) {
				DeleteMyBullet(i);
				enemyTanks[j].decreaseHp();
				if (enemyTanks[j].getHp() == 0) {
					DeleteTank(j);
				}
				i--;
				break;
			}
		}

		if (DeleteBlock(myBullets[i])) {
			DeleteEnemyBullet(i);
			i--;
		}
	}

	for (auto &enemyTank : enemyTanks) {
		Fire(enemyTank);
	}
	
}

void GameControl::Fire(Tank &tank) {
	tank.increaseCount();
	if (tank.getCount() == 0) {
		Bullet bullet = Bullet(tank.getPosX(), tank.getPosY(), tank.getDir());
		enemyBullets.push_back(bullet);
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
	return maze.deleteBlock(bullet.getPosX()/GRID_SIZE, bullet.getPosY()/GRID_SIZE);
}

/**
 * Delete blocks that have the same position with enemy's bullets
 */
void GameControl::DeleteEnemyBullet(int index) {
	enemyBullets.erase(enemyBullets.begin() + index);
}

/**
 * Delete blocks that have the same position with player's bullets
 */
void GameControl::DeleteMyBullet(int index) {
	myBullets.erase(myBullets.begin() + index);
}

/**
 * Increase the score
 */
void GameControl::UpdateScore() {
	score++;
}

void GameControl::ProduceTank() {
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






