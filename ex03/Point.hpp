/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:32:55 by dmusulas          #+#    #+#             */
/*   Updated: 2025/06/26 19:32:55 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
    const Fixed x;
    const Fixed y;

public:
    // Default constructor
    Point();

    // Constructor with float parameters
    Point(const float x, const float y);

    // Copy constructor
    Point(const Point &other);

    // Copy assignment operator
    Point &operator=(const Point &other);

    // Destructor
    ~Point();

    // Getters
    Fixed getX() const;
    Fixed getY() const;
};

// BSP function
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif // POINT_HPP
