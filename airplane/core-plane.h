#pragma once
#ifndef AIRPLANE_WARS_PLANE_H
#define AIRPLANE_WARS_PLANE_H

#include <utility>
using std::pair;

class plane {
public:
	int    rad = 100;               // ÅÐ¶¨Ô²°ë¾¶
	int    maxHp = 0;
	int    NowHp = 0;
	pair<double, double> coord;    // ×ø±ê
	int    Vshoot = 10;     // Éä»÷¼ä¸ô£¨Ö¡Êý£©
	int    atk = 10;               // ×Óµ¯ÉËº¦
	int    camp = 0;              // 0: Íæ¼Ò£»1: µÐ»ú

	virtual ~plane() = default;
};


#endif
