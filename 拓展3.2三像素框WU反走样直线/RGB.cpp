#include "StdAfx.h"
#include "RGB.h"
#include"math.h"


CRGB::CRGB()
{
	red = 1.0;
	green = 1.0;
	blue = 1.0;
}


CRGB::~CRGB()
{
}
CRGB::CRGB(double red,double green,double blue)//重载构造函数
{
	this->red = red;
	this->green = green;
	this->blue = blue;
}

CRGB operator +(CRGB &c1, CRGB &c2)        //“+”运算符重载
{
	CRGB c;
	c.red = c1.red + c2.red;
	c.green = c1.green + c2.green;
	c.blue = c1.blue + c2.blue;
	return c;
}
CRGB operator -(CRGB &c1, CRGB &c2)        //“-”运算符重载
{
	CRGB c;
	c.red = c1.red - c2.red;
	c.green = c1.green - c2.green;
	c.blue = c1.blue - c2.blue;
	return c;
}
CRGB operator -(double n, CRGB &c2)        //“-”运算符重载
{
	CRGB c;
	c.red = n - c2.red;
	c.green = n - c2.green;
	c.blue = n - c2.blue;
	return c;
}
CRGB operator *(CRGB &c1, CRGB &c2)       //“*”运算符重载
{
	CRGB c;
	c.red = c1.red * c2.red;
	c.green = c1.green * c2.green;
	c.blue = c1.blue * c2.blue;
	return c;
}
CRGB operator *(CRGB &c1, double n)     //“*”运算符重载
{
   CRGB c;
   c.red = n * c1.red;
   c.green =n * c1.green;
   c.blue = n * c1.blue;
   return c;
}
CRGB operator *(double n, CRGB &c1)//“*”运算符重载
{
   CRGB c;
   c.red = n * c1.red;
   c.green = n * c1.green;
   c.blue = n * c1.blue;
   return c;
}
CRGB operator /(CRGB &c1,double n) // “/”运算符重载
{
if(fabs(n)<1e-6)
		n = 1.0;
   CRGB c;
   c.red = c1.red / n;
   c.green = c1.green / n;
   c.blue = c1.blue / n;
   return c;
}

