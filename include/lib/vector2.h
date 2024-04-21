#ifndef __VECTOR2_H__
#define __VECTOR2_H__

struct Vector2
{
    float x;
    float y;

    Vector2(float x, float y) : x(x), y(y) {}
};

class Lib
{
public:
    static Vector2 AddVector2(const Vector2 &v1, const Vector2 &v2);
};

#endif