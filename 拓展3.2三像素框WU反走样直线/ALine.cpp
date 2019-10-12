#include "StdAfx.h"
#include "ALine.h"
#include "ALine.h"
#include <math.h>
#define Round(d) int(floor(d + 0.5))

CALine::CALine(void)
{
}


CALine::~CALine(void)
{
}
void CALine::MoveTo(CDC* pDC, CP2 P0)//绘制直线起点函数
{
	this->P0 = P0;
}

void CALine::MoveTo(CDC* pDC, double x0, double y0)
{
	CRGB c0 = CRGB(0.0, 0.0, 0.0);
	P0 = CP2(x0, y0, c0);
}

void CALine::MoveTo(CDC* pDC, double x0, double y0, CRGB c0)//重载函数
{
	P0 = CP2(x0, y0, c0);
}

void CALine::LineTo(CDC* pDC, CP2 P1)
{
	this->P1 = P1;
	CP2 p;
	CRGB c0, c1 ,c2;
	if(fabs(P0.x - P1.x) < 1e-4)//绘制垂线
	{
		if(P0.y > P1.y)
		{
			for(p = P0;p.y > P1.y;p.y--)
			{
				c0 = P0.c;
				pDC->SetPixelV(Round(p.x - 1), Round(p.y), RGB(c0.red * 255, c0.green * 255, c0.blue * 255));
				pDC->SetPixelV(Round(p.x), Round(p.y), RGB(c0.red * 255, c0.green * 255, c0.blue * 255));
				pDC->SetPixelV(Round(p.x + 1), Round(p.y), RGB(c0.red * 255, c0.green * 255, c0.blue * 255));
			}
		}
		if(P0.y < P1.y)
		{
			for(p = P0;p.y < P1.y;p.y++)
			{
				c0 = P0.c;
				pDC->SetPixelV(Round(p.x - 1), Round(p.y), RGB(c0.red * 255, c0.green * 255, c0.blue * 255));
				pDC->SetPixelV(Round(p.x), Round(p.y), RGB(c0.red * 255, c0.green * 255, c0.blue * 255));
				pDC->SetPixelV(Round(p.x + 1), Round(p.y), RGB(c0.red * 255, c0.green * 255, c0.blue * 255));
			}
		}
	}
	else
	{
		double k, e;
		k = (P1.y - P0.y) / (P1.x - P0.x);
		if(k > 1.0)//绘制k>1
		{
			if(P0.y > P1.y)
			{
				e = 0.0;
				for(p = P0;p.y > P1.y;p.y--)
				{
					c0 = P0.c;
					c1 = CRGB(fabs(e), fabs(e), fabs(e));
					c2 = 1.0 - c1;
					pDC->SetPixelV(Round(p.x + 1), Round(p.y), RGB(c1.red * 255, c1.green * 255, c1.blue * 255));
					pDC->SetPixelV(Round(p.x), Round(p.y), RGB(c0.red * 255, c0.green * 255, c0.blue * 255));
					pDC->SetPixelV(Round(p.x - 1), Round(p.y), RGB(c2.red * 255, c2.green * 255, c2.blue * 255));
					e -= 1/k;
					if(e <= -1.0)
					{
						p.x--;
						e++;
					}
				}
			}
			if(P0.y < P1.y)
			{
				e = 0.0;
				for(p = P0;p.y < P1.y;p.y++)
				{
					c0 = P0.c;
					c1 = CRGB(fabs(e), fabs(e), fabs(e));
					c2 = 1.0 - c1;
					pDC->SetPixelV(Round(p.x - 1), Round(p.y), RGB(c1.red * 255, c1.green * 255, c1.blue * 255));
					pDC->SetPixelV(Round(p.x), Round(p.y), RGB(c0.red * 255, c0.green * 255, c0.blue * 255));
					pDC->SetPixelV(Round(p.x + 1), Round(p.y), RGB(c2.red * 255, c2.green * 255, c2.blue * 255));
					e += 1/k;
					if(e >= 1.0)
					{
						p.x++;
						e--;
					}		 
				}
			}
		}
		if(0.0 <= k && k <= 1.0)//绘制0<=k<=1
		{
			if(P0.x > P1.x)
			{
				e = 0.0;
				for(p = P0;p.x > P1.x;p.x--)
				{
					c0 = P0.c;
					c1 = CRGB(fabs(e), fabs(e), fabs(e));
					c2 = 1.0 - c1;
					pDC->SetPixelV(Round(p.x), Round(p.y + 1), RGB(c1.red * 255, c1.green * 255, c1.blue * 255));
					pDC->SetPixelV(Round(p.x), Round(p.y), RGB(c0.red * 255, c0.green * 255, c0.blue * 255));
					pDC->SetPixelV(Round(p.x), Round(p.y - 1), RGB(c2.red * 255, c2.green * 255, c2.blue * 255));
					e -= k;
					if(e <= -1.0)
					{
						p.y--;
						e++;
					}
				}
			}
			if(P0.x < P1.x)
			{
				e = 0.0;
				for(p = P0;p.x < P1.x;p.x++)
				{
					c0 = P0.c;
					c1 = CRGB(fabs(e), fabs(e), fabs(e));
					c2 = 1.0 - c1;
					pDC->SetPixelV(Round(p.x), Round(p.y - 1), RGB(c1.red * 255, c1.green * 255, c1.blue * 255));
					pDC->SetPixelV(Round(p.x), Round(p.y), RGB(c0.red * 255, c0.green * 255, c0.blue * 255));
					pDC->SetPixelV(Round(p.x), Round(p.y + 1), RGB(c2.red * 255, c2.green * 255, c2.blue * 255));
					e += k;
					if(e >= 1.0)
					{
						p.y++;
						e--;
					}
				}
			}
		}
		if(k >= -1.0 && k < 0.0)//绘制-1=<k<0
		{
			if(P0.x > P1.x)
			{
				e = 0.0;
				for(p = P0;p.x > P1.x;p.x--)
				{
					c0 = P0.c;
					c1 = CRGB(fabs(e), fabs(e), fabs(e));
					c2 = 1.0 - c1;
					pDC->SetPixelV(Round(p.x), Round(p.y - 1), RGB(c1.red * 255, c1.green * 255, c1.blue * 255));
					pDC->SetPixelV(Round(p.x), Round(p.y), RGB(c0.red * 255, c0.green * 255, c0.blue * 255));
					pDC->SetPixelV(Round(p.x), Round(p.y + 1), RGB(c2.red * 255, c2.green * 255, c2.blue * 255));
					e -= k;
					if(e >= 1.0)
					{
						p.y++;
						e--;
					}
				}
			}
			if(P0.x < P1.x)
			{
				e = 0.0;
				for(p = P0;p.x < P1.x;p.x++)
				{
					c0 = P0.c;
					c1 = CRGB(fabs(e), fabs(e), fabs(e));
					c2 = 1.0 - c1;
					pDC->SetPixelV(Round(p.x), Round(p.y + 1), RGB(c1.red * 255, c1.green * 255, c1.blue * 255));
					pDC->SetPixelV(Round(p.x), Round(p.y), RGB(c0.red * 255, c0.green * 255, c0.blue * 255));
					pDC->SetPixelV(Round(p.x), Round(p.y - 1), RGB(c2.red * 255, c2.green * 255, c2.blue * 255));
					e += k;
					if(e <= -1.0)
					{
						p.y--;
						e++;
					}
				}
			}
		}
		if(k < -1.0)//绘制k<-1
		{
			if(P0.y < P1.y)
			{
				e = 0.0;
				for(p = P0;p.y < P1.y;p.y++)
				{
					c0 = P0.c;
					c1 = CRGB(fabs(e), fabs(e), fabs(e));
					c2 = 1.0 - c1;
					pDC->SetPixel(Round(p.x + 1), Round(p.y), RGB(c1.red * 255, c1.green * 255, c1.blue * 255));
					pDC->SetPixel(Round(p.x), Round(p.y), RGB(c0.red * 255, c0.green * 255, c0.blue * 255));
					pDC->SetPixel(Round(p.x - 1), Round(p.y), RGB(c2.red * 255, c2.green * 255, c2.blue * 255));
					e += 1/k;
					if(e <= -1.0)
					{
						p.x--;
						e++;
					}
				}
			}
			if(P0.y > P1.y)
			{
				e = 0.0;
				for(p = P0;p.y > P1.y;p.y--)
				{
					c0 = P0.c;
					c1 = CRGB(fabs(e), fabs(e), fabs(e));
					c2 = 1.0 - c1;
					pDC->SetPixel(Round(p.x - 1), Round(p.y), RGB(c1.red * 255, c1.green * 255, c1.blue * 255));
					pDC->SetPixel(Round(p.x), Round(p.y), RGB(c0.red * 255, c0.green * 255, c0.blue * 255));
					pDC->SetPixel(Round(p.x + 1), Round(p.y), RGB(c2.red * 255, c2.green * 255, c2.blue * 255));
					e -= 1/k;
					if(e >= 1.0)
					{
						p.x++;
						e--;
					}
				}
			}
		}
	}
	this->P0 = P1;
}

void CALine::LineTo(CDC* pDC, double x1, double y1)
{
	CRGB c1 = CRGB(0.0, 0.0, 0.0);
	P1 = CP2(x1, y1, c1);
	LineTo(pDC, P1);
}

void CALine::LineTo(CDC* pDC, double x1, double y1, CRGB c1)//重载函数
{
	P1 = CP2(x1, y1, c1);
	LineTo(pDC, P1);
}

