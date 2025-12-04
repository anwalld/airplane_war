#include"Res-GameRes.h"
Resourse::Resourse() {
	loadimage(&GameBG, "image\\ui\\bgp.png", 1920, 1080);
	Resourse::loadingPlayer();
	Resourse::loadingEnemy();
	Resourse::loadingBullet();
	Resourse::loadingProp();
}
void Resourse::loadingPlayer() {

	loadimage(&PlayerImgs[0], "image\\player\\0.png");
	loadimage(&PlayerImgs[1], "image\\player\\1.png");
	loadimage(&PlayerImgs[2], "image\\player\\2.png");
	loadimage(&PlayerImgs[3], "image\\player\\3.png");



}
void Resourse::loadingEnemy() {
	loadimage(&EnemyImgs[0], "image\\enemy\\common.png");
	loadimage(&EnemyImgs[1], "image\\enemy\\elite.png");
	loadimage(&EnemyImgs[2], "image\\enemy\\boss.png");
}
void Resourse::loadingBullet() {
	loadimage(&bulletImgs[0], "image\\bullet\\0.png");
	loadimage(&bulletImgs[1], "image\\bullet\\1.png");
	loadimage(&bulletImgs[2], "image\\bullet\\2.png");
	loadimage(&bulletImgs[3], "image\\bullet\\3.png");
	loadimage(&bulletImgs[4], "image\\bullet\\4.png");
	loadimage(&bulletImgs[5], "image\\bullet\\5.png");
	loadimage(&bulletImgs[6], "image\\bullet\\6.png");
	loadimage(&bulletImgs[7], "image\\bullet\\7.png");
	loadimage(&bulletImgs[8], "image\\bullet\\8.png");
	loadimage(&bulletImgs[9], "image\\bullet\\9.png");
	loadimage(&bulletImgs[10], "image\\bullet\\10.png");
}
void Resourse::loadingProp() {
	loadimage(&PropImgs[0], "image\\prop\\0.png");
	loadimage(&PropImgs[1], "image\\prop\\1.png");
	loadimage(&PropImgs[2], "image\\prop\\2.png");
	loadimage(&PropImgs[3], "image\\prop\\3.png");
	loadimage(&PropImgs[4], "image\\prop\\4.png");
	loadimage(&PropImgs[5], "image\\prop\\5.png");
	loadimage(&PropImgs[6], "image\\prop\\6.png");
	loadimage(&PropImgs[7], "image\\prop\\7.png");
	loadimage(&PropImgs[8], "image\\prop\\8.png");
	loadimage(&PropImgs[9], "image\\prop\\9.png");
	loadimage(&PropImgs[10], "image\\prop\\10.png");


}