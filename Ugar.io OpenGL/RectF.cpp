#include "RectF.h"
#include <exception>

RectF::RectF() {
	x = 0.0f;
	y = 0.0f;
	w = 0.0f;
	h = 0.0f;
}

RectF::RectF(float _x, float _y, float _w, float _h) {
	x = _x;
	y = _y;
	w = _w;
	h = _h;
}


RectF::~RectF() {
}

void RectF::setX(float _x)
{
	x = _x;
}

void RectF::setY(float _y)
{
	y = _y;
}

void RectF::setW(float _w)
{
	w = _w;
}

void RectF::setH(float _h)
{
	h = _h;
}

const float RectF::getX()
{
		return x;
}

const float RectF::getY()
{
		return y;
}

const float RectF::getW()
{
		return w;
}

const float RectF::getH()
{
		return h;
}
