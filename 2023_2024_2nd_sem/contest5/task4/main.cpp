#include <cmath>

int gcd(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return std::abs(a);
}

class Rational
{
private:
    int num;
    int denom;

public:
    Rational(int n = 0, int d = 1)
    {
        int g = gcd(n, d);
        if (0 > d)
        {
            num = n / g * (-1);
            denom = d / g * (-1);
        }
        else
        {
            num = n / g;
            denom = d / g;
        }
    }

    Rational operator+(Rational b) const
    {
        int n = (num * b.denom) + (b.num * denom);
        int d = denom * b.denom;
        int g = gcd(n, d);
        return Rational(n / g, d / g);
    }

    Rational operator-(Rational b) const
    {
        int n = (num * b.denom) - (b.num * denom);
        int d = denom * b.denom;
        int g = gcd(n, d);
        return Rational(n / g, d / g);
    }

    Rational operator*(Rational b) const
    {
        int n = num * b.num;
        int d = denom * b.denom;
        int g = gcd(n, d);
        return Rational(n / g, d / g);
    }

    Rational operator/(Rational b) const
    {
        int n = num * b.denom;
        int d = denom * b.num;
        int g = gcd(n, d);
        return Rational(n / g, d / g);
    }

    bool operator==(Rational b) const
    {
        return (num == b.num) && (denom == b.denom);
    }

    bool operator!=(Rational b) const
    {
        return (num != b.num) || (denom != b.denom);
    }

    Rational& operator+=(Rational b)
    {
        num = (num * b.denom) + (b.num * denom);
        denom = denom * b.denom;
        int g = gcd(num, denom);
        num = num / g;
        denom = denom / g;
        return *this;
    }

    Rational& operator=(Rational b)
    {
        num = b.num;
        denom = b.denom;
        return *this;
    }

    Rational& operator-=(Rational b)
    {
        num = (num * b.denom) - (b.num * denom);
        denom = denom * b.denom;
        int g = gcd(num, denom);
        num = num / g;
        denom = denom / g;
        return *this;
    }

    Rational& operator*=(Rational b)
    {
        num = num * b.num;
        denom = denom * b.denom;
        int g = gcd(num, denom);
        num = num / g;
        denom = denom / g;
        return *this;
    }

    Rational& operator/=(Rational b)
    {
        num = num * b.denom;
        denom = denom * b.num;
        int g = gcd(num, denom);
        if (0 > denom)
        {
            num = num / g * (-1);
            denom = denom / g * (-1);
        }
        else
        {
            num = num / g;
            denom = denom / g;
        }
        return *this;
    }

    int numerator() const
    {
        return num;
    }
    int denominator() const
    {
        return denom;
    }

    Rational operator+() const
    {
        return Rational(num, denom);
    }

    Rational operator-() const
    {
        return Rational(-num, denom);
    }

    Rational& operator++()
    {
        num += denom;
        return *this;
    }

    Rational& operator--()
    {
        num -= denom;
        return *this;
    }

    Rational operator++(int)
    {
        Rational a = *this;
        ++(*this);
        return a;
    }

    Rational operator--(int)
    {
        Rational a = *this;
        --(*this);
        return a;
    }
};

Rational operator+(int a, Rational b)
{
    return Rational(b.numerator() + a * b.denominator(), b.denominator());
}

Rational operator-(int a, Rational b)
{
    return Rational(b.numerator() - a * b.denominator(), b.denominator());
}

Rational operator*(int a, Rational b)
{
    return Rational(b.numerator() * a, b.denominator());
}

Rational operator/(int a, Rational b)
{
    return Rational(b.denominator() * a, b.numerator());
}