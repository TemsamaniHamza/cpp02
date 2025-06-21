#include "Fixed.hpp"

// Fixed::Fixed() : save_value(0) {
//     std::cout << "Default constructor called" << std::endl;
// };

Fixed::Fixed() : save_value(0) {
    std::cout << "Default constructor called" << std::endl;
};

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

float Fixed::toFloat( void ) const
{
    return((float)this->save_value / 256);
};

int Fixed::toInt( void ) const
{
    return(this->save_value / 256);
};


std::ostream& operator<<(std::ostream& outp, const Fixed& fixed)
{  
    outp << fixed.toFloat();  // print the float value of Fixed
    return outp; 

};

Fixed::Fixed(const Fixed& copy) {
    std::cout << "Copy constructor called" << std::endl;
    this->save_value = copy.save_value; 
};


Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->save_value = other.save_value;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->save_value);
};


void Fixed::setRawBits( int const raw ) {
    this->save_value = raw;
};
