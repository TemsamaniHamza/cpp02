#ifndef Fixed_hpp
#define Fixed_hpp

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
private:
    int save_value;
    static const int save_bits = 8;

public:
    Fixed();
    Fixed(const int n);
    Fixed(const float n);
    Fixed(const Fixed &copy);
    ~Fixed();

    friend std::ostream &operator<<(std::ostream &outp, const Fixed &fixed);
    Fixed &operator=(const Fixed &second);

    bool operator>(const Fixed &obj) const;
    bool operator<(const Fixed &obj) const;
    bool operator>=(const Fixed &obj) const;
    bool operator<=(const Fixed &obj) const;
    bool operator==(const Fixed &obj) const;
    bool operator!=(const Fixed &obj) const;

    Fixed operator+(const Fixed &obj) const;
    Fixed operator-(const Fixed &obj) const;
    Fixed operator*(const Fixed &obj) const;
    Fixed operator/(const Fixed &obj) const;

    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);

    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);

    int toInt(void) const;
    float toFloat(void) const;
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif