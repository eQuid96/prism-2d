#include "lib/vector2.h"

Vector2 Lib::AddVector2(const Vector2 &v1, const Vector2 &v2)
{
    return Vector2(v1.x + v2.x, v1.y + v2.y);
}