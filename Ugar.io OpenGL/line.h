#ifndef LINE_H
#define LINE_H
#include "Vector2.h"
#include "Color.h"

class Line {

public:

    Vector2 *start;// = new Vector2();
    Vector2 *end;// = new Vector2();
    Color *color;// = new Color();

    Vector2* drawableStart;// = new Vector2();
    Vector2* drawableEnd;// = new Vector2();


    Line();
    Line(Vector2 *_start, Vector2 *_end, Color *_color);

    ~Line();

    void UpdateDrawableLine(float xoffset, float yoffset, float scale);

	void Draw();

};

#endif // LINE_H
