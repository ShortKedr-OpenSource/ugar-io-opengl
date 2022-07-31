#include "camera.h"


Camera::Camera() {
	viewportSize = new Vector2(0, 0);
	observedPosition = new Vector2(0, 0);
    scale = 1.0f;
}

Camera::Camera(Vector2 *vs, Vector2 *op, float _scale)
{
	viewportSize = new Vector2(0, 0);
	observedPosition = new Vector2(0, 0);
    scale = 1.0f;

    *viewportSize = *vs;
    *observedPosition = *op;
    scale = _scale;
}

Camera::~Camera()
{
    delete viewportSize;
    delete observedPosition;
}

float Camera::GetNormalXOffset()
{
    return observedPosition->x * scale - (viewportSize->x / 2.0f);
}

float Camera::GetNormalYOffset()
{
    return observedPosition->y * scale - (viewportSize->y / 2.0f);
}

void Camera::SetCamera(Vector2 *vs, Vector2 *op)
{
    *viewportSize = *vs;
    *observedPosition = *op;
}

void Camera::SetCamera(Vector2 *vs, Vector2 *op, float _scale)
{
    *viewportSize = *vs;
    *observedPosition = *op;
    scale = _scale;
}
