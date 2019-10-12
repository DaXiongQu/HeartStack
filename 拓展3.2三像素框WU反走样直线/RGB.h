#pragma once
class CRGB
{
public:
	CRGB();
	virtual ~CRGB();
	CRGB(double red,double green,double blue);//���캯������
	friend CRGB operator+(CRGB &c1, CRGB &c2);//���������
	friend CRGB operator-(CRGB &c1, CRGB &c2);
	friend CRGB operator-(double n, CRGB &c2);
	friend CRGB operator*(CRGB &c1, CRGB &c2);
	friend CRGB operator*(CRGB &c, double n);
	friend CRGB operator*(double n,CRGB &c);
	friend CRGB operator/(CRGB &,double n);
public:
	double red;
	double green;
	double blue;
};

