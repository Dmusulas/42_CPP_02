/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:33:20 by dmusulas          #+#    #+#             */
/*   Updated: 2025/06/26 19:33:54 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Default constructor
Point::Point() : x(0), y(0) {}

// Constructor with float parameters
Point::Point(const float x_val, const float y_val) : x(x_val), y(y_val) {}

// Copy constructor
Point::Point(const Point &other) : x(other.x), y(other.y) {}

// Copy assignment operator
// NOTE: Since x and y are const, we cannot reassign them
// This assignment operator will not actually change the values
// but we implement it for Orthodox Canonical Form compliance
Point &Point::operator=(const Point &other) {
    (void)other;
    return *this;
}

// Destructor
Point::~Point() {}

// Getters
Fixed Point::getX() const { return x; }

Fixed Point::getY() const { return y; }
