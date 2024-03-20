#include "cmath"


class Complex
{
private:
    double real;
    double imaginary;

public:
    Complex(double r, double i = 0)
    {
        real = r;
        imaginary = i;
    };

    Complex& operator=(const Complex& other)
    {
        real = other.real;
        imaginary = other.imaginary;
        return *this;
    }

    Complex operator+(const Complex& other) const
    {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    Complex operator-(const Complex& other) const
    {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    Complex operator*(const Complex& other) const
    {
        return Complex(real * other.real - imaginary * other.imaginary,
                       real * other.imaginary + imaginary * other.real);
    }

    Complex operator/(const Complex other) const
    {
        double dev = other.real * other.real + other.imaginary * other.imaginary;
        return Complex((real * other.real + imaginary * other.imaginary) / dev,
                       (imaginary * other.real - real * other.imaginary) / dev);
    }

    Complex operator+() const
    {
        return Complex(real, imaginary);
    }

    Complex operator-() const
    {
        return Complex(-real, -imaginary);
    }

    double Re() const
    {
        return real;
    }

    double Im() const
    {
        return imaginary;
    }

    bool operator==(Complex other) const
    {
        return real == other.real && imaginary == other.imaginary;
    }

    bool operator!=(Complex other) const
    {
        return real != other.real || imaginary != other.imaginary;
    }
};

Complex reversed(Complex other)
{
    return Complex(other.Re(), -other.Im());
}

Complex operator+(double num, const Complex& other)
{
    return other + num;
}

Complex operator-(double num, const Complex& other)
{
    return -other + num;
}

Complex operator*(double num, const Complex& other)
{
    return other * num;
}

Complex operator/(double n, const Complex& other)
{
    Complex numerator = reversed(other) * n;
    Complex denominator = other * reversed(other);
    return numerator / denominator.Re();
}

double abs(const Complex& other)
{
    return std::sqrt(other.Re() * other.Re() + other.Im() * other.Im());
}