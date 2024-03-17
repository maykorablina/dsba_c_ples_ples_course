#include <cmath>

class Complex
{
private:
    double real_part;
    double imaginary_part;

public:
    Complex(double r_p, double i_p = 0) : real_part(r_p), imaginary_part(i_p) {}

    Complex operator+(Complex b) const
    {
        return Complex(real_part + b.real_part, imaginary_part + b.imaginary_part);
    }

    Complex operator-(Complex b) const
    {
        return Complex(real_part - b.real_part, imaginary_part - b.imaginary_part);
    }

    Complex operator*(Complex b) const
    {
        return Complex(real_part * b.real_part - imaginary_part * b.imaginary_part,
                       real_part * b.imaginary_part + imaginary_part * b.real_part);
    }

    Complex operator/(Complex b) const
    {
        double divisor = b.real_part * b.real_part + b.imaginary_part * b.imaginary_part;
        return Complex((real_part * b.real_part + imaginary_part * b.imaginary_part) / divisor,
                       (imaginary_part * b.real_part - real_part * b.imaginary_part) / divisor);
    }

    bool operator==(Complex b) const
    {
        return (real_part == b.real_part) && (imaginary_part == b.imaginary_part);
    }

    bool operator!=(Complex b) const
    {
        return (real_part != b.real_part) || (imaginary_part != b.imaginary_part);
    }

    Complex operator+() const
    {
        return Complex(real_part, imaginary_part);
    }

    Complex operator-() const
    {
        return Complex(-real_part, -imaginary_part);
    }

    double Re() const
    {
        return real_part;
    }

    double Im() const
    {
        return imaginary_part;
    }
};

Complex operator+(double a, Complex b)
{
    return Complex(b.Re() + a, b.Im());
}

Complex operator-(double a, Complex b)
{
    return Complex(a - b.Re(), b.Im());
}

Complex operator*(double a, Complex b)
{
    return Complex(a * b.Re(), a * b.Im());
}

Complex operator/(double a, Complex b)
{
    return Complex((a * b.Re()) / (b.Re() * b.Re() + b.Im() * b.Im()),
                   (a * b.Im()) / (b.Re() * b.Re() + b.Im() * b.Im()));
}

double abs(Complex a)
{
    double sum = a.Re() * a.Re() + a.Im() * a.Im();
    return std::sqrt(sum);
}
