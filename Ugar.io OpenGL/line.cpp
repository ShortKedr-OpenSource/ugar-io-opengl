#include "line.h"
#include "Vector2.h"
#include "Color.h"
#include "GLBasics.h"

Line::Line() {
	start = new Vector2();
    end = new Vector2();
    color = new Color();
    drawableStart = new Vector2();
    drawableEnd = new Vector2();
}

Line::Line(Vector2 *_start, Vector2 *_end, Color *_color) {

	start = new Vector2();
    end = new Vector2();
    color = new Color();
    drawableStart = new Vector2();
    drawableEnd = new Vector2();

    *start = *_start;
    *end =*_end;
    *color = *_color;
}

Line::~Line()
{
    delete start;
    delete end;
    delete color;
    delete drawableEnd;
    delete drawableStart;
}

void Line::UpdateDrawableLine(float xoffset, float yoffset, float scale)
{
    drawableStart->x = (start->x*scale)-xoffset;
    drawableStart->y = (start->y*scale)-yoffset;

    drawableEnd->x = (end->x*scale)-xoffset;
    drawableEnd->y = (end->y*scale)-yoffset;
}

void Line::Draw()
{
	GLBasics::DrawLine(drawableStart->x, drawableStart->y, drawableEnd->x, drawableEnd->y, color);
}
