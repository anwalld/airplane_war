cmake_minimum_required(VERSION 3.31)
project(airplane_wars CXX)

set(CMAKE_C_STANDARD 11)

include_directories(arch)
include_directories(arch/behavior)
include_directories(arch/core)
include_directories(arch/system)
include_directories(arch/manager)
include_directories(src)

add_executable(airplane_wars
        arch/system/engine.h
        arch/core/Player.h
        arch/system/system.h
        arch/system/view.h
        arch/core/plane.h
        arch/core/Enemy.h
        arch/core/bullet.h
        arch/core/prop.h
        arch/manager/PlayerManager.h
        arch/manager/EnemyManager.h
        arch/manager/BulletManager.h
        arch/manager/PropManager.h
        arch/manager/GameManager.h
        arch/behavior/BulletBehavior.h
        arch/behavior/EnemyBehavior.h
        arch/behavior/PlayerBehavior.h
        arch/behavior/PropBehavior.h
        src/manager/BulletManager.cpp
        arch/behavior/PlaneBehavior.h
        src/Behavior/PlaneBehavior.cpp
        src/manager/PropManager.cpp

)
