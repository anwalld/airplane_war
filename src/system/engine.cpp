#include "system/engine.h"
#include <time.h>
void AllGame::ChangeGameTime() {
    frameCount++;
    if (frameCount%120==0) {
        GameTime += 1;
    }
}
int AllGame::ChangeDifWitchTime() {
    // 计算基于游戏时间的新难度值
    // 每30秒游戏时间增加1个难度等级(暂定)
    if (GameTime%30==0)AllGame::instance().dif++;
    return AllGame::instance().dif;
}
