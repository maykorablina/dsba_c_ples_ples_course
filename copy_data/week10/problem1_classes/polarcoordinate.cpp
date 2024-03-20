#include "polarcoordinate.h"
#include "vector2d.h"
#include "cmath"


PolarCoordinate::PolarCoordinate(double radius, double angle): _radius(radius), _angle(angle) {}

PolarCoordinate& PolarCoordinate::operator= (const PolarCoordinate &b){
    _radius = b._radius;
    _angle = b._angle;
    return *this;
}

PolarCoordinate vec2d_to_polar(Vector2d vec){
    double p = vec.magnitude();
    double phi = atan2(vec.getY(), vec.getX());

    return {p, phi};
}

Vector2d polar_to_vec2d(PolarCoordinate polar){
    double x = polar.getRadius() * cos(polar.getAngle());
    double y = polar.getRadius() * sin(polar.getAngle());

    return {x, y};
}

PolarCoordinate PolarCoordinate::operator+(const PolarCoordinate &b) const{
    Vector2d vec1 = polar_to_vec2d(*this),
            vec2 = polar_to_vec2d(b);

    return vec2d_to_polar(vec1 + vec2);
}

PolarCoordinate PolarCoordinate::operator-(const PolarCoordinate& b) const{
    Vector2d vec1 = polar_to_vec2d(*this),
            vec2 = polar_to_vec2d(b);

    return vec2d_to_polar(vec1 - vec2);
}

PolarCoordinate& PolarCoordinate::operator+=(const PolarCoordinate& b){
    Vector2d vec1 = polar_to_vec2d(*this),
            vec2 = polar_to_vec2d(b);

    Vector2d vec3 = vec1 + vec2;
    PolarCoordinate a = vec2d_to_polar(vec3);
    _radius = a._radius;
    _angle = a._angle;

    return *this;
}
PolarCoordinate& PolarCoordinate::operator-=(const PolarCoordinate& b){
    Vector2d vec1 = polar_to_vec2d(*this),
            vec2 = polar_to_vec2d(b);

    Vector2d vec3 = vec1 - vec2;
    PolarCoordinate a = vec2d_to_polar(vec3);
    _radius = a._radius;
    _angle = a._angle;

    return *this;
}

PolarCoordinate PolarCoordinate::operator*(double b) const{
    Vector2d vec = polar_to_vec2d(*this);

    return vec2d_to_polar(vec * b);
}

PolarCoordinate PolarCoordinate::operator/(double b) const{
    Vector2d vec = polar_to_vec2d(*this);

    return vec2d_to_polar(vec / b);
}

PolarCoordinate& PolarCoordinate::operator*=(double b){
    Vector2d vec = polar_to_vec2d(*this);

    PolarCoordinate a = vec2d_to_polar(vec * b);
    _radius = a._radius;
    _angle = a._angle;

    return *this;
}
PolarCoordinate& PolarCoordinate::operator/=(double b){
    Vector2d vec = polar_to_vec2d(*this);

    PolarCoordinate a = vec2d_to_polar(vec / b);
    _radius = a._radius;
    _angle = a._angle;

    return *this;
}
