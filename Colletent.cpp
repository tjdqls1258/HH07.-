#include "Colletent.h"


Colletent* Colletent::s_pInstance = 0;

Colletent::Colletent()
{
}


Colletent::~Colletent()
{
}
void Colletent::setPostion1(int x1, int y1, int h1, int w1)
{
	this->x1 = x1;
	this->y1 = y1;
	this->h1 = x1 + w1;
	this->w1 = y1 + h1;
	pParams1_redy = true;
}
void Colletent::setPostion2(int x2, int y2,int h2,int w2)
{
	this->x2 = x2;
	this->y2 = y2;
	this->w2 = x2 + w2;
	this->h2 = y2 + h2;
	pParams2_redy = true;
}
bool Colletent::getColletent()
{
	if (pParams1_redy && pParams2_redy)
	{
		if (w1 < x2) return false;
		if (h1 < y2) return false;
		if (x1 > w2) return false;
		if (y1 > h2) return false;

		return true;
	}
	return false;
}