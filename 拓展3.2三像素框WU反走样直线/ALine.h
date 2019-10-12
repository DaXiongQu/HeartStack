#pragma once
#include"P2.h"
class CALine
{
public:
	CALine();
	virtual ~CALine();
	void MoveTo(CDC* pDC, CP2 P0);//移动到指定位置
	void MoveTo(CDC* pDC, double x0, double y0);
	void MoveTo(CDC* pDC, double x0, double y0, CRGB c0);
	void LineTo(CDC* pDC, CP2 P1);//绘制直线，不含终点
	void LineTo(CDC* pDC, double x1, double y1);
	void LineTo(CDC* pDC, double x1, double y1, CRGB c1);
private:
	CP2 P0;//起点
	CP2 P1;//终点
};

