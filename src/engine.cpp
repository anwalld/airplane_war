#include "engine.h"
#include <time.h>

// 静态变量用于记录上次更新时间
static time_t lastUpdateTime = 0;
// 实现ChangeGameTime接口，使GameTime随游戏时间以秒为单位增加
void AllGame::ChangeGameTime() {
    // 获取当前时间
    time_t currentTime = time(nullptr);    
    // 如果是第一次调用，初始化lastUpdateTime并返回
    if (lastUpdateTime == 0) {
        lastUpdateTime = currentTime;
        return;
    }
    // 计算时间差（秒）
    int timeDifference = (int)(currentTime - lastUpdateTime);    
    // 如果时间有变化，更新GameTime和lastUpdateTime
    if (timeDifference > 0) {
        GameTime += timeDifference;
        lastUpdateTime = currentTime;
    }
}

int AllGame::ChangeDifWitchTime() {
    // 计算基于游戏时间的新难度值
    // 每30秒游戏时间增加1个难度等级(暂定)
    int newDif = GameTime / 30;
    
    // 确保难度值单调递增
    if (newDif > dif) {
        dif = newDif;
    }
    
    // 返回更新后的难度值
    return dif;
}
