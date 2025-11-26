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
