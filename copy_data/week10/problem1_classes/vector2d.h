#ifndef VECTOR_2D
#define VECTOR_2D

class Vector2d
{
public:
    Vector2d();

    Vector2d(double x, double y);

    Vector2d(const Vector2d& v2);

    double getX() const;

    void setX(double x);

    double getY() const;

    void setY(double y);

    double magnitude() const;

    Vector2d operator+ (const Vector2d& v2) const;

    Vector2d operator- (const Vector2d& v2) const;

    Vector2d operator/ (double d) const;

    Vector2d operator* (double d) const;

private:
    double _x;
    double _y;
};

#endif