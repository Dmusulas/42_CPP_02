/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:34:12 by dmusulas          #+#    #+#             */
/*   Updated: 2025/06/26 19:40:23 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed crossProduct(Point const &p1, Point const &p2,
                          Point const &point) {
    return (p2.getX() - p1.getX()) * (point.getY() - p1.getY()) -
           (p2.getY() - p1.getY()) * (point.getX() - p1.getX());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    // Calculate cross products for each edge
    Fixed d1 = crossProduct(a, b, point);
    Fixed d2 = crossProduct(b, c, point);
    Fixed d3 = crossProduct(c, a, point);

    // Check if point is on any edge (cross product is zero)
    if (d1 == Fixed(0) || d2 == Fixed(0) || d3 == Fixed(0))
        return false;

    // Point is inside if all cross products have the same sign
    // (all positive or all negative)
    bool hasNeg = (d1 < Fixed(0)) || (d2 < Fixed(0)) || (d3 < Fixed(0));
    bool hasPos = (d1 > Fixed(0)) || (d2 > Fixed(0)) || (d3 > Fixed(0));

    return !(hasNeg && hasPos);
}
