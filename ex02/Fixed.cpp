#include "Fixed.hpp"

// Fixed::Fixed() : save_value(0) {
//     std::cout << "Default constructor called" << std::endl;
// };

Fixed::Fixed() : save_value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
    std::cout << "int constructor called" << std::endl;
    this->save_value = n << save_bits;
}

Fixed::Fixed(const float n)
{
    std::cout << "float constructor called" << std::endl;
    this->save_value = (int)roundf(n * 256);
}

float Fixed::toFloat(void) const
{
    return ((float)this->save_value / 256);
}

int Fixed::toInt(void) const
{
    return (this->save_value / 256);
}

std::ostream &operator<<(std::ostream &outp, const Fixed &fixed)
{
    outp << fixed.toFloat(); // print the float value of Fixed
    return outp;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->save_value = copy.save_value;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->save_value = other.save_value;
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->save_value);
}

void Fixed::setRawBits(int const raw)
{
    this->save_value = raw;
}

bool Fixed::operator>(const Fixed &obj) const
{
    return (this->save_bits > obj.save_value);
}

bool Fixed::operator<(const Fixed &obj) const
{
    return (this->save_bits < obj.save_value);
};
bool Fixed::operator>=(const Fixed &obj) const
{
    return (this->save_bits >= obj.save_value);
}

bool Fixed::operator<=(const Fixed &obj) const
{
    return (this->save_bits <= obj.save_value);
}

bool Fixed::operator==(const Fixed &obj) const
{
    return (this->save_bits == obj.save_value);
}

bool Fixed::operator!=(const Fixed &obj) const
{
    return (this->save_bits != obj.save_value);
}

Fixed Fixed::operator+(const Fixed &obj) const
{
    Fixed ret;
    ret.setRawBits(this->save_value + obj.save_value);
    return (ret);
}

Fixed Fixed::operator-(const Fixed &obj) const
{
    Fixed ret;
    ret.setRawBits(this->save_value - obj.save_value);
    return (ret);
}



Fixed Fixed::operator*(const Fixed &obj) const
{
    Fixed ret;
    long temp = (long)this->save_value * (long)obj.save_value;
    ret.setRawBits((int)(temp >> save_bits));
    return (ret);
}

Fixed Fixed::operator/(const Fixed &obj) const
{
    Fixed ret;
    long temp = (long)this->save_value / (long)obj.save_value;
    ret.setRawBits((int)(temp >> save_bits));
    return (ret);
}

Fixed &Fixed::operator++()
{
    ++this->save_value;
    return *this;
}
Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    ++this->save_value;
    return temp;
}
Fixed &Fixed::operator--()
{
    --this->save_value;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    --this->save_value;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return a;
    return b;
}