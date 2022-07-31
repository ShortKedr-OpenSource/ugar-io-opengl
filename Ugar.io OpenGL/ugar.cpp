#include "ugar.h"
#include "Color.h"
#include "Vector2.h"
#include "RectF.h"
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "food.h"
#include "GLBasics.h"
#include <iostream>

const float Ugar::COLLISION_DISTANCE = 0.1f;
const float Ugar::U_DIFFERENCE = 0.00001f;
const float Ugar::SIZE_LERP = 0.1f;
const float Ugar::FRICTION = 0.1f;
const float Ugar::MAX_SPEED_INC = 0.4f;
const float Ugar::MAX_SPEED_SIZE_DEC = 0.35f;
const float Ugar::SPEED_SIZE_DEC = 0.005f;

Ugar::Ugar() {
	position = new Vector2();
	radius = 0.0f;
    showedRadius = 0.0f;
	currentSpeed = new Vector2();
	currentSpeedInc = 0.0f;
	color = new Color(0, 0, 0);
	drawingRect = new RectF(0, 0, 0 ,0);
}

Ugar::Ugar(Vector2*_position, float _radius)
{
	position = new Vector2();
    showedRadius = 0.0f;
	currentSpeed = new Vector2();
	currentSpeedInc = 0.0f;
	drawingRect = new RectF(0, 0, 0 ,0);

	color = new Color(0, 0, 0);
    color->setRGB(rand() % 256, rand() % 256, rand() % 256);
    *position = *_position;
    radius = _radius;
}

Ugar::~Ugar()
{
    if (position) delete position;
    if (currentSpeed) delete currentSpeed;
    if (color) delete color;
    if (drawingRect) delete drawingRect;
}

void Ugar::Update()
{
    UpdateSize();
    UpdateSpeedInc();
    position->x = position->x + currentSpeed->x;
    position->y = position->y + currentSpeed->y;
    currentSpeed->x = currentSpeed->x - currentSpeed->x * FRICTION;
    currentSpeed->y = currentSpeed->y - currentSpeed->y * FRICTION;
}

void Ugar::UpdateDrawingRect(float xoffset, float yoffset, float scale)
{
    drawingRect->setX((position->x - showedRadius) * scale - xoffset);
    drawingRect->setY((position->y - showedRadius) * scale - yoffset);
    drawingRect->setW(showedRadius * 2.0f * scale);
    drawingRect->setH(showedRadius * 2.0f * scale);
}

void Ugar::UpdateSpeedInc()
{
    float decrement = radius * SPEED_SIZE_DEC;
    currentSpeedInc = MAX_SPEED_INC - ((decrement < MAX_SPEED_SIZE_DEC) ? decrement : MAX_SPEED_SIZE_DEC);
}

void Ugar::UpdateSize()
{
    if (fabsf(radius-showedRadius) <= U_DIFFERENCE) return;
    showedRadius += (radius - showedRadius) * SIZE_LERP;
}

bool Ugar::CheckFoodCollision(Food *target)
{
    float xDist = position->x - target->position->x;
    float yDist = position->y - target->position->y;

    float dist = sqrtf(xDist*xDist + yDist*yDist);
    float collisionDist = radius + (target->radius*0.6f);
    if (dist <= collisionDist) return true;
    else return false;
}

void Ugar::SetPosition(float x, float y)
{
    position->x = x;
    position->y = y;
}

void Ugar::Move(float x, float y)
{
    UpdateSpeedInc();
    float sum = fabsf(x)+fabsf(y);
    currentSpeed->x = currentSpeed->x + ((sum != 0.0f) ? x/sum : 0) * currentSpeedInc;
    currentSpeed->y = currentSpeed->y + ((sum != 0.0f) ? y/sum : 0) * currentSpeedInc;
}

void Ugar::MoveDirection(float direction)
{
    float xmul = (float)((INVERT_X) ? -cosf(direction*M_PI/180.0f) : cosf(direction*M_PI/180.0f));
    float ymul = (float)((INVERT_Y) ? -sinf(direction*M_PI/180.0f) : sinf(direction*M_PI/180.0f));

    UpdateSpeedInc();
    currentSpeed->x = currentSpeed->x + currentSpeedInc * xmul;
    currentSpeed->y = currentSpeed->y + currentSpeedInc * ymul;
}

float Ugar::GetSquare() {
    return M_PI * radius * radius;
}

void Ugar::SetSquare(float square)
{
    radius = sqrtf(square / (float)M_PI);
}

void Ugar::Draw() {
	GLBasics::DrawCircle(drawingRect->getX()+ drawingRect->getW()/2.0f, drawingRect->getY() + drawingRect->getH() / 2.0f, drawingRect->getH() / 2.0f, color, (int)(16.0f * (showedRadius/5.0f)));
};

bool Ugar::CheckCollision(Ugar *target, bool *isLesser)
{
    float xDist = position->x - target->position->x;
    float yDist = position->y - target->position->y;

    float dist = sqrtf(xDist*xDist + yDist*yDist);
    float collisionDist = (radius > target->radius) ? radius + (target->radius*0.6f) : (radius * 0.6f) + target->radius;
    if (radius < target->radius) *isLesser = true;
    else *isLesser = false;
    if (dist <= collisionDist) return true;
    else return false;
}
