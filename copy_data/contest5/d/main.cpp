#include "iostream"

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return std::abs(a);
}

class Rational
{
private:
    int numer;
    int denomin;

public:
    Rational(int n = 0, int d = 1)
    {
        if (d == 0)
        {
            std::cout << "denominator is 0\n";
            return;
        }

        int nod = gcd(n, d);
        if (d < 0)
        {
            numer = -n / nod;
            denomin = -d / nod;
        }
        else
        {
            numer = n / nod;
            denomin = d / nod;
        }
    };

    Rational& operator=(const Rational& other)
    {
        numer = other.numer;
        denomin = other.denomin;
        return *this;
    }

    Rational operator+(const Rational& other) const
    {
        int num = numer * other.denomin + other.numer * denomin;
        int den = denomin * other.denomin;
        int nod = gcd(num, den);
        return Rational(num / nod, den / nod);
    }

    Rational& operator+=(const Rational& other)
    {
        numer = numer * other.denomin + other.numer * denomin;
        denomin = denomin * other.denomin;
        int nod = gcd(numer, denomin);
        numer /= nod, denomin /= nod;
        return *this;
    }

    Rational operator-(const Rational& other) const
    {
        int num = numer * other.denomin - other.numer * denomin;
        int den = denomin * other.denomin;
        int nod = gcd(num, den);
        return Rational(num / nod, den / nod);
    }

    Rational& operator-=(const Rational& other)
    {
        numer = numer * other.denomin - other.numer * denomin;
        denomin = denomin * other.denomin;
        int nod = gcd(numer, denomin);
        numer /= nod, denomin /= nod;
        return *this;
    }

    Rational operator*(const Rational& other) const
    {
        int num = numer * other.numer;
        int den = denomin * other.denomin;
        int nod = gcd(num, den);
        return Rational(num / nod, den / nod);
    }

    Rational& operator*=(const Rational& other)
    {
        numer = numer * other.numer;
        denomin = denomin * other.denomin;
        int nod = gcd(numer, denomin);
        numer /= nod, denomin /= nod;
        return *this;
    }

    Rational operator/(const Rational other) const
    {
        int num = numer * other.denomin;
        int den = denomin * other.numer;
        num = den < 0 ? -num : num;
        den = den < 0 ? -den : den;
        int nod = gcd(num, den);
        return Rational(num / nod, den / nod);
    }

    Rational& operator/=(const Rational other)
    {
        numer = numer * other.denomin;
        denomin = denomin * other.numer;
        int nod = gcd(numer, denomin);
        numer = denomin < 0 ? -numer : numer;
        denomin = denomin < 0 ? -denomin : denomin;
        numer /= nod, denomin /= nod;
        return *this;
    }

    Rational operator+() const
    {
        return Rational(numer, denomin);
    }

    Rational operator-() const
    {
        return Rational(-numer, denomin);
    }

    Rational& operator++()
    {
        numer += denomin;
        return *this;
    }

    Rational operator++(int)
    {
        Rational temp = *this;
        ++(*this);
        return temp;
    }

    Rational& operator--()
    {
        numer -= denomin;
        return *this;
    }

    Rational operator--(int)
    {
        Rational temp = *this;
        --(*this);
        return temp;
    }

    double numerator() const
    {
        return numer;
    }

    double denominator() const
    {
        return denomin;
    }

    bool operator==(const Rational& other) const
    {
        return numer == other.numer && denomin == other.denomin;
    }

    bool operator!=(const Rational& other) const
    {
        return numer != other.numer || denomin != other.denomin;
    }
};

Rational operator+(int num, const Rational& other)
{
    return other + num;
}

Rational operator-(int num, const Rational& other)
{
    return -other + num;
}

Rational operator*(int num, const Rational& other)
{
    return other * num;
}

Rational operator/(int num, const Rational& other)
{
    num *= other.denominator();
    int nod = gcd(num, other.numerator());
    return Rational(num / nod, other.numerator() / nod);
}

int main(){
    Rational a(1, 1);
    Rational b(3, 1);
    a = a * -1;
    b = +b;

    std::cout << a.numerator() << '/' << a.denominator() << ' ' << b.numerator() << '/' << b.denominator();

    return 0;
}