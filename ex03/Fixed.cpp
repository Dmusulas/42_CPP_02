/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:43:06 by dmusulas          #+#    #+#             */
/*   Updated: 2025/06/26 19:21:54 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() { fixedPointValue = 0; }

// Integer constructor

Fixed::Fixed(const int value) { fixedPointValue = value << fractionalBits; }

// Float constructor
Fixed::Fixed(const float value) {
    fixedPointValue = static_cast<int>(roundf(value * (1 << fractionalBits)));
}

// Copy constructor
Fixed::Fixed(const Fixed &other) { *this = other; }

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        setRawBits(other.fixedPointValue);
    }
    return *this;
}

// Destructor
Fixed::~Fixed() {}

int Fixed::getRawBits(void) const { return fixedPointValue; }

void Fixed::setRawBits(int const raw) { fixedPointValue = raw; }

float Fixed::toFloat(void) const {
    return static_cast<float>(fixedPointValue) / (1 << fractionalBits);
}

int Fixed::toInt(void) const { return fixedPointValue >> fractionalBits; }

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}

// Comparison operators
bool Fixed::operator>(const Fixed &other) const {
    return fixedPointValue > other.fixedPointValue;
}

bool Fixed::operator<(const Fixed &other) const {
    return fixedPointValue < other.fixedPointValue;
}

bool Fixed::operator>=(const Fixed &other) const {
    return fixedPointValue >= other.fixedPointValue;
}

bool Fixed::operator<=(const Fixed &other) const {
    return fixedPointValue <= other.fixedPointValue;
}

bool Fixed::operator==(const Fixed &other) const {
    return fixedPointValue == other.fixedPointValue;
}

bool Fixed::operator!=(const Fixed &other) const {
    return fixedPointValue != other.fixedPointValue;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const {
    Fixed result;
    result.setRawBits(fixedPointValue + other.fixedPointValue);
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed result;
    result.setRawBits(fixedPointValue - other.fixedPointValue);
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed result;
    result.setRawBits((fixedPointValue * other.fixedPointValue) >>
                      fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
    Fixed result;
    result.setRawBits((fixedPointValue << fractionalBits) /
                      other.fixedPointValue);
    return result;
}

// Increment/decrement operators
Fixed &Fixed::operator++() {
    fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    fixedPointValue++;
    return temp;
}

Fixed &Fixed::operator--() {
    fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    fixedPointValue--;
    return temp;
}

// Static min/max functions
Fixed &Fixed::min(Fixed &a, Fixed &b) { return (a < b) ? a : b; }

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) { return (a > b) ? a : b; }

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}
