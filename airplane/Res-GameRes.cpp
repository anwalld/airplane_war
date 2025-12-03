#include"Res-GameRes.h"
Resourse::Resourse() {
	Resourse::loadingPlayer();
	Resourse::loadingEnemy();
	Resourse::loadingBullet();
	Resourse::loadingProp();
}
void Resourse::loadingPlayer() {

	loadimage(&PlayerImgs[0], "image\\player\\0.png", 100, 100);
	loadimage(&PlayerImgs[1], "image\\player\\1.png", 100, 100);
	loadimage(&PlayerImgs[2], "image\\player\\2.png", 100, 100);
	loadimage(&PlayerImgs[3], "image\\player\\3.png", 100, 100);



}
void Resourse::loadingEnemy() {
	loadimage(&EnemyImgs[0], "image\\enemy\\common.jpg", 22, 22);
	loadimage(&EnemyImgs[0], "image\\enemy\\elite.jpg", 30, 30);
	loadimage(&EnemyImgs[0], "image\\enemy\\boss.jpg", 35, 35);



}
void Resourse::loadingBullet() {
	loadimage(&bulletImgs[0], "image\\bullet\\0.png", 30, 30);
	loadimage(&bulletImgs[1], "image\\bullet\\1.jpg", 30, 30);
	loadimage(&bulletImgs[2], "image\\bullet\\2.png", 30, 30);
	loadimage(&bulletImgs[3], "image\\bullet\\3.png", 40, 40);
	loadimage(&bulletImgs[4], "image\\bullet\\4.jpg", 40, 40);
	loadimage(&bulletImgs[5], "image\\bullet\\5.png", 40, 40);
	loadimage(&bulletImgs[6], "image\\bullet\\6.png", 50, 50);
	loadimage(&bulletImgs[7], "image\\bullet\\7.jpg", 50, 50);
	loadimage(&bulletImgs[8], "image\\bullet\\8.jpg", 50, 50);
	loadimage(&bulletImgs[9], "image\\bullet\\9.jpg", 32, 32);
	loadimage(&bulletImgs[10], "image\\bullet\\10.jpg", 32, 32);
}
void Resourse::loadingProp() {
	loadimage(&PropImgs[0], "image\\prop\\0.png", 100, 100);
	loadimage(&PropImgs[1], "image\\prop\\1.png", 100, 100);
	loadimage(&PropImgs[2], "image\\prop\\2.png", 100, 100);
	loadimage(&PropImgs[3], "image\\prop\\3.png", 100, 100);
	loadimage(&PropImgs[4], "image\\prop\\4.png", 100, 100);
	loadimage(&PropImgs[5], "image\\prop\\5.png", 100, 100);
	loadimage(&PropImgs[6], "image\\prop\\6.png", 100, 100);
	loadimage(&PropImgs[7], "image\\prop\\7.png", 100, 100);
	loadimage(&PropImgs[8], "image\\prop\\8.png", 100, 100);
	loadimage(&PropImgs[9], "image\\prop\\9.png", 100, 100);
	loadimage(&PropImgs[10], "image\\prop\\10.png", 100, 100);


}