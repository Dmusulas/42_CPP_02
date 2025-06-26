/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:42:47 by dmusulas          #+#    #+#             */
/*   Updated: 2025/06/26 19:19:35 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>
class Fixed {
private:
    int fixedPointValue;
    static const int fractionalBits = 8;

public:
    // Default constructor
    Fixed();

    // Integer constructor
    Fixed(const int value);

    // Float constructor
    Fixed(const float value);

    // Copy constructor
    Fixed(const Fixed &other);

    // Copy assignment operator
    Fixed &operator=(const Fixed &other);

    // Destructor
    ~Fixed();

    // Comparison operators
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    // Arithmetic operators
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    // Increment/decrement operators
    Fixed &operator++();   // pre-increment
    Fixed operator++(int); // post-increment
    Fixed &operator--();   // pre-decrement
    Fixed operator--(int); // post-decrement

    // Static min/max functions
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif // FIXED_HPP
