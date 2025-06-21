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

    float toFloat(void) const;
    int toInt(void) const;
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif