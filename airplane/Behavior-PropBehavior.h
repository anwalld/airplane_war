#pragma once
#ifndef AIRPLANE_WARS_PROPBEHAVIOR_H
#define AIRPLANE_WARS_PROPBEHAVIOR_H
#include "core-prop.h"
#include"Mgr-BulletMgr.h"
#include"Mgr-EnemyMgr.h"
//生成道具的类型和编号
std::pair<int, int> RandomTypeAndNum(Player* player, prop* p);
//随机生成坐标
std::pair<double, double>RandomProduceCoord(prop* p);
//计算落叶移动速度
std::pair<double, double>LeaveMoveVxAndVy(prop* p);
//根据速度计算移动速度
std::pair<double, double>PropMoveCoord(prop* p);
//道具的具体功能实现
//0--永久加属性类
//0.0减小飞机vShoot
void PropEffect_DecreaseVShoot(Player* player, prop* p);
//0.1增加子弹伤害
void PropEffect_IncreaseBulletDamage(Player* player, prop* p);
//0.2增加飞机MaxHp
void PropEffect_IncreasePlaneMaxHp(Player* player, prop* p);
//0.3增加飞机speed
void PropEffect_IncreasePlaneSpeed(Player* player, prop* p);
//1--一次性道具类
//1.0回血
void PropEffect_Heal(Player* player, prop* p);
//1.1清屏
void PropEffect_ClearScreen(BulletManager&b,EnemyManager&e,prop* p);
//1.2全屏炸弹
void PropEffect_FullScreenBomb(EnemyManager& e, prop* p);
//2--限时类
//2.0激光武器
void PropEffect_LaserWeapon(Player* player, prop* p);
//2.1超级子弹
void PropEffect_SuperBullet(Player* player, prop* p);
//2.2临时减少杀敌数(降低难度)
void PropEffect_DecreaseDif(prop* p);
//2.3无敌(更改身份识别)(要求生成概率不高于10%)
void PropEffect_Invincible(Player* player, prop* p);
#endif //AIRPLANE_WARS_PROPBEHAVIOR_H