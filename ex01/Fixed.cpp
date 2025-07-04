/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:43:06 by dmusulas          #+#    #+#             */
/*   Updated: 2025/07/04 15:20:01 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() {
    fixedPointValue = 0;
    std::cout << "Default constructor called" << std::endl;
}

/**
 * @brief Constructs a Fixed object from an integer value.
 *
 * Converts the given integer to its fixed-point representation by left-shifting
 * the value by the number of fractional bits (8). This effectively multiplies
 * the integer by 2^8 = 256 to preserve the integer part in the upper bits.
 *
 * @param value The integer value to convert to fixed-point format
 *
 * @example
 * Fixed f(10);  // Stores 10 << 8 = 2560 internally, represents 10.0
 */

Fixed::Fixed(const int value) {
    fixedPointValue = value << fractionalBits;
    std::cout << "Int constructor called" << std::endl;
}

/**
 * @brief Constructs a Fixed object from a floating-point value.
 *
 * Converts the given float to its fixed-point representation by multiplying
 * by 2^fractionalBits (256) and rounding to the nearest integer. This process
 * maps the continuous float value to the discrete fixed-point representation.
 *
 * @param value The floating-point value to convert to fixed-point format
 *
 * @note Uses roundf() for proper rounding to handle fractional parts accurately
 * @note Some precision loss may occur due to the discrete nature of fixed-point
 *
 * @example
 * Fixed f(42.42f);  // Stores round(42.42 * 256) = 10860 internally
 */
Fixed::Fixed(const float value) {
    fixedPointValue = static_cast<int>(roundf(value * (1 << fractionalBits)));
    std::cout << "Float constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        setRawBits(other.fixedPointValue);
    }
    return *this;
}

// Destructor
Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

/**
 * @brief Converts the fixed-point value to a floating-point representation.
 *
 * Transforms the internal fixed-point representation back to a float by
 * dividing the raw value by 2^fractionalBits (256). This recovers the
 * original decimal value with some potential precision loss.
 *
 * @return The floating-point representation of the fixed-point value
 *
 * @note The returned value may not exactly match the original float used
 *       in construction due to fixed-point quantization
 *
 * @example
 * Fixed f(42.42f);
 * float result = f.toFloat();  // Returns approximately 42.421875
 */
float Fixed::toFloat(void) const {
    return static_cast<float>(fixedPointValue) / (1 << fractionalBits);
}

/**
 * @brief Converts the fixed-point value to an integer representation.
 *
 * Extracts the integer part of the fixed-point value by right-shifting
 * the raw value by the number of fractional bits (8). This effectively
 * divides by 2^8 = 256 and truncates the fractional part.
 *
 * @return The integer part of the fixed-point value (fractional part discarded)
 *
 * @note This performs truncation, not rounding. For example, 3.9 becomes 3
 *
 * @example
 * Fixed f(42.42f);
 * int result = f.toInt();  // Returns 42 (fractional part .42 is discarded)
 */
int Fixed::toInt(void) const { return fixedPointValue >> fractionalBits; }

/**
 * @brief Gets the raw internal representation of the fixed-point value.
 *
 * Returns the unprocessed integer value that stores the fixed-point number.
 * This raw value represents the actual number multiplied by 2^fractionalBits.
 * Useful for debugging or when direct access to the internal representation
 * is needed.
 *
 * @return The raw integer value storing the fixed-point representation
 *
 * @note This function prints a debug message when called
 *
 * @example
 * Fixed f(10);
 * int raw = f.getRawBits();  // Returns 2560 (10 * 256)
 */
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return fixedPointValue;
}

/**
 * @brief Sets the raw internal representation of the fixed-point value.
 *
 * Directly sets the internal integer value without any conversion. The
 * provided raw value should already be in the correct fixed-point format
 * (i.e., actual_value * 2^fractionalBits).
 *
 * @param raw The raw integer value to set as the fixed-point representation
 *
 *
 * @example
 * Fixed f;
 * f.setRawBits(2560);  // Sets the value to represent 10.0 (2560 / 256)
 */
void Fixed::setRawBits(int const raw) { fixedPointValue = raw; }

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}
