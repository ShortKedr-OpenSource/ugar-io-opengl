#ifndef UGAR_H
#define UGAR_H
#include "Vector2.h"
#include "RectF.h"
#include "Color.h"
#include "food.h"

class Ugar {

public:

    Vector2 *position;// = new Vector2(0.0, 0.0);

    float radius;// = 0.5f;
    float showedRadius;// = 0.5f;

    Vector2 *currentSpeed;// = new Vector2(0.0, 0.0);
    float currentSpeedInc;// = 0.5f;

    Color *color;// = new Color(0, 0, 0);

    RectF *drawingRect;// = new RectF(0, 0, 0 ,0);


    Ugar();
    Ugar(Vector2 *_position, float _radius);
    virtual ~Ugar();

    virtual void Update();
    void UpdateSize();
    void UpdateDrawingRect(float xoffset, float yoffset, float scale);
    void UpdateSpeedInc();

    bool CheckCollision(Ugar *target, bool *isLesser);
    bool CheckFoodCollision(Food *target);

    void SetPosition(float x, float y);

    void Move(float x, float y);
    void MoveDirection(float direction);

    float GetSquare();
    void SetSquare(float square);
	void Draw();

private:
    static const bool INVERT_X = false;
    static const bool INVERT_Y = true;

    static const float COLLISION_DISTANCE;// = 0.1f;
    static const float U_DIFFERENCE;// = 0.00001f;
    static const float SIZE_LERP;// = 0.1f;

    static const float FRICTION;// = 0.1f;

	static const float MAX_SPEED_INC;// = 0.4f;
	static const float MAX_SPEED_SIZE_DEC;// = 0.35f;
	static const float SPEED_SIZE_DEC;// = 0.005f;

};

#endif // UGAR_H
