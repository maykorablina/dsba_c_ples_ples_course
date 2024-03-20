#include <cmath>
#include "vector2d.h"


Vector2d::Vector2d(): _x(0), _y(0){}

Vector2d::Vector2d(double x, double y): _x(x), _y(y){}

Vector2d::Vector2d(const Vector2d& v2): _x(v2._x), _y(v2._y){}

double Vector2d::getX() const
{
    return _x;
}

void Vector2d::setX(double x)
{
    _x = x;
}

double Vector2d::getY() const
{
    return _y;
}

void Vector2d::setY(double y)
{
    _y = y;
}

double Vector2d::magnitude() const{
    return std::sqrt(_x * _x + _y * _y);
}

Vector2d Vector2d::operator+ (const Vector2d& v2) const{
    return {_x + v2.getX(), _y + v2.getY()};
}

Vector2d Vector2d::operator- (const Vector2d& v2) const{
    return {_x - v2.getX(), _y - v2.getY()};
}

Vector2d Vector2d::operator/ (double d) const{
    return {_x / d, _y / d};
}

Vector2d Vector2d::operator* (double d) const{
    return {_x * d, _y * d};
}
