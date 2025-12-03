#include "system-engine.h"
#include <time.h>
void AllGame::ChangeGameTime() {
    AllGame::instance().frameCount++;
    if (AllGame::instance().frameCount % 120 == 0) {
        AllGame::instance().GameTime += 1;
    }
}
int AllGame::ChangeDifWithTime() {
    // 计算基于游戏时间的新难度值
    // 每30秒游戏时间增加1个难度等级(暂定)
    if (AllGame::instance().GameTime % 30 == 0)AllGame::instance().dif++;
    return AllGame::instance().dif;
}

double AllGame::CalculateCoef() {
    // 计算系数
    double coef = 0.65 * (1.0*AllGame::instance().GameTime / (5 * 60)) + 0.2 * (1.0*AllGame::instance().AllKill / 500)+0.15*(AllGame::instance().dif/(5*2));
    return coef >= 1 ? 1 : coef;
}
std::tuple<int, int, double> PlaneInitDataShow::planeAttr[4] = {
    std::make_tuple(150, 10, 1.0 * 200 / 120),  // 0号
    std::make_tuple(100, 15, 1.0 * 200 / 120),  // 1号
    std::make_tuple(100, 10, 1.0 * 250 / 120),  // 2号
    std::make_tuple(120, 12, 1.0 * 220 / 120)   // 3号
};