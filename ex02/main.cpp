/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:33:11 by dmusulas          #+#    #+#             */
/*   Updated: 2025/06/26 19:23:59 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) {
    std::cout << "=== Subject Tests ===" << std::endl;
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << "a: " << a << std::endl;
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;

    std::cout << "\n=== Constructor Tests ===" << std::endl;
    Fixed c;        // Default constructor
    Fixed d(42);    // Integer constructor
    Fixed e(3.14f); // Float constructor
    Fixed f(d);     // Copy constructor
    std::cout << "Default: " << c << std::endl;
    std::cout << "Int(42): " << d << std::endl;
    std::cout << "Float(3.14): " << e << std::endl;
    std::cout << "Copy of d: " << f << std::endl;

    std::cout << "\n=== Assignment Operator ===" << std::endl;
    Fixed g;
    g = e;
    std::cout << "g = e: " << g << std::endl;

    std::cout << "\n=== Comparison Operators ===" << std::endl;
    Fixed x(10);
    Fixed y(5);
    Fixed z(10);
    std::cout << "x(10) > y(5): " << (x > y) << std::endl;
    std::cout << "x(10) < y(5): " << (x < y) << std::endl;
    std::cout << "x(10) >= z(10): " << (x >= z) << std::endl;
    std::cout << "x(10) <= y(5): " << (x <= y) << std::endl;
    std::cout << "x(10) == z(10): " << (x == z) << std::endl;
    std::cout << "x(10) != y(5): " << (x != y) << std::endl;

    std::cout << "\n=== Arithmetic Operators ===" << std::endl;
    Fixed num1(8);
    Fixed num2(4);
    std::cout << "num1(8) + num2(4): " << (num1 + num2) << std::endl;
    std::cout << "num1(8) - num2(4): " << (num1 - num2) << std::endl;
    std::cout << "num1(8) * num2(4): " << (num1 * num2) << std::endl;
    std::cout << "num1(8) / num2(4): " << (num1 / num2) << std::endl;

    std::cout << "\n=== Increment/Decrement Operators ===" << std::endl;
    Fixed inc(5);
    std::cout << "Initial inc: " << inc << std::endl;
    std::cout << "Pre-increment ++inc: " << ++inc << std::endl;
    std::cout << "After pre-increment: " << inc << std::endl;
    std::cout << "Post-increment inc++: " << inc++ << std::endl;
    std::cout << "After post-increment: " << inc << std::endl;
    std::cout << "Pre-decrement --inc: " << --inc << std::endl;
    std::cout << "After pre-decrement: " << inc << std::endl;
    std::cout << "Post-decrement inc--: " << inc-- << std::endl;
    std::cout << "After post-decrement: " << inc << std::endl;

    std::cout << "\n=== Min/Max Functions ===" << std::endl;
    Fixed min1(3.5f);
    Fixed min2(7.2f);
    std::cout << "min1: " << min1 << ", min2: " << min2 << std::endl;
    std::cout << "min(min1, min2): " << Fixed::min(min1, min2) << std::endl;
    std::cout << "max(min1, min2): " << Fixed::max(min1, min2) << std::endl;

    // Test const versions
    const Fixed const_min1(1.5f);
    const Fixed const_min2(2.5f);
    std::cout << "const_min1: " << const_min1 << ", const_min2: " << const_min2
              << std::endl;
    std::cout << "min(const_min1, const_min2): "
              << Fixed::min(const_min1, const_min2) << std::endl;
    std::cout << "max(const_min1, const_min2): "
              << Fixed::max(const_min1, const_min2) << std::endl;

    std::cout << "\n=== Conversion Functions ===" << std::endl;
    Fixed conv(42.42f);
    std::cout << "conv(42.42f) toFloat(): " << conv.toFloat() << std::endl;
    std::cout << "conv(42.42f) toInt(): " << conv.toInt() << std::endl;
    std::cout << "conv(42.42f) getRawBits(): " << conv.getRawBits()
              << std::endl;

    std::cout << "\n=== setRawBits Test ===" << std::endl;
    Fixed raw_test;
    raw_test.setRawBits(1024); // 1024 >> 8 = 4
    std::cout << "After setRawBits(1024): " << raw_test << std::endl;

    return 0;
}
