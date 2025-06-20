#ifndef Fixed_hpp
#define Fixed_hpp

#include <iostream>
#include <string>

class Fixed
{
    private :
        int save_value;
        static const int save_bits = 8;
    public :
        Fixed();
        Fixed(const Fixed& copy);
        Fixed& operator=(const Fixed& second);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif 