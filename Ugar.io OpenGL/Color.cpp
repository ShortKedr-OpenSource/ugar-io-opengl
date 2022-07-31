#include "Color.h"


Color::Color() {
	r = 0.0f;
	g = 0.0f;
	b = 0.0f;
}

Color::Color(float _r, float _g, float _b)
{
	r = _r;
	g = _g;
	b = _b;
}


Color::~Color()
{
}

void Color::setRGB(float _r, float _g, float _b)
{
	r = _r;
	g = _g;
	b = _b;
}

Color * Color::normalized(float normalize)
{
	float max = 255.0f;
	return new Color((r / max)*normalize, (g / max)*normalize, (b / max)*normalize);
}
