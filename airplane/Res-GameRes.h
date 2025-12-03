#pragma once
#ifndef AIRPLANE_WARS_GAME_RESOURSE_H 
#define AIRPLANE_WARS_GAME_RESOURSE_H 
#include<graphics.h>
#include<easyx.h>
#include <vector>
class Resourse {
public:
	IMAGE GameBG;
	std::vector<IMAGE> bulletImgs = std::vector<IMAGE>(11);
	std::vector<IMAGE> PlayerImgs = std::vector<IMAGE>(4);
	std::vector<IMAGE> PropImgs = std::vector<IMAGE>(11);
	std::vector<IMAGE> EnemyImgs = std::vector<IMAGE>(3);
	Resourse();
	void loadingPlayer();
	void loadingEnemy();
	void loadingBullet();
	void loadingProp();
};
#endif 


