#pragma once
#ifndef AIRPLANE_WARS_PLANE_H
#define AIRPLANE_WARS_PLANE_H

#include <utility>
using std::pair;

class plane {
public:
	int    rad = 50;               // ÅÐ¶¨Ô²°ë¾¶
	int    maxHp = 100;
	int    NowHp = 100;
	pair<double, double> coord = {0,0};    // ×ø±ê
	int    Vshoot = 10;     // Éä»÷¼ä¸ô£¨Ö¡Êý£©
	int    atk = 50;               // ×Óµ¯ÉËº¦
	int    camp = 0;              // 0: Íæ¼Ò£»1: µÐ»ú
	int    skin = 0;               // Æ¤·ô±àºÅ
	virtual ~plane() = default;
};


#endif
