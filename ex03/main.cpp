/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:33:11 by dmusulas          #+#    #+#             */
/*   Updated: 2025/06/26 19:34:58 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main(void) {
    std::cout << "=== BSP Tests ===" << std::endl;

    // Define a triangle with vertices at (0,0), (4,0), (2,3)
    Point a(0.0f, 0.0f);
    Point b(4.0f, 0.0f);
    Point c(2.0f, 3.0f);

    std::cout << "Triangle vertices:" << std::endl;
    std::cout << "A: (" << a.getX() << ", " << a.getY() << ")" << std::endl;
    std::cout << "B: (" << b.getX() << ", " << b.getY() << ")" << std::endl;
    std::cout << "C: (" << c.getX() << ", " << c.getY() << ")" << std::endl;
    std::cout << std::endl;

    // Test points inside the triangle
    Point inside1(2.0f, 1.0f);
    Point inside2(1.5f, 0.5f);
    Point inside3(2.5f, 1.5f);

    std::cout << "Points inside triangle:" << std::endl;
    std::cout << "Point (" << inside1.getX() << ", " << inside1.getY()
              << "): " << (bsp(a, b, c, inside1) ? "INSIDE" : "OUTSIDE")
              << std::endl;
    std::cout << "Point (" << inside2.getX() << ", " << inside2.getY()
              << "): " << (bsp(a, b, c, inside2) ? "INSIDE" : "OUTSIDE")
              << std::endl;
    std::cout << "Point (" << inside3.getX() << ", " << inside3.getY()
              << "): " << (bsp(a, b, c, inside3) ? "INSIDE" : "OUTSIDE")
              << std::endl;
    std::cout << std::endl;

    // Test points outside the triangle
    Point outside1(0.0f, 2.0f);
    Point outside2(5.0f, 1.0f);
    Point outside3(2.0f, -1.0f);

    std::cout << "Points outside triangle:" << std::endl;
    std::cout << "Point (" << outside1.getX() << ", " << outside1.getY()
              << "): " << (bsp(a, b, c, outside1) ? "INSIDE" : "OUTSIDE")
              << std::endl;
    std::cout << "Point (" << outside2.getX() << ", " << outside2.getY()
              << "): " << (bsp(a, b, c, outside2) ? "INSIDE" : "OUTSIDE")
              << std::endl;
    std::cout << "Point (" << outside3.getX() << ", " << outside3.getY()
              << "): " << (bsp(a, b, c, outside3) ? "INSIDE" : "OUTSIDE")
              << std::endl;
    std::cout << std::endl;

    // Test points on vertices (should return false)
    std::cout << "Points on vertices (should be OUTSIDE):" << std::endl;
    std::cout << "Point A: " << (bsp(a, b, c, a) ? "INSIDE" : "OUTSIDE")
              << std::endl;
    std::cout << "Point B: " << (bsp(a, b, c, b) ? "INSIDE" : "OUTSIDE")
              << std::endl;
    std::cout << "Point C: " << (bsp(a, b, c, c) ? "INSIDE" : "OUTSIDE")
              << std::endl;
    std::cout << std::endl;

    // Test points on edges (should return false)
    Point edge1(2.0f, 0.0f); // Middle of edge AB
    Point edge2(1.0f, 1.5f); // On edge AC
    Point edge3(3.0f, 1.5f); // On edge BC

    std::cout << "Points on edges (should be OUTSIDE):" << std::endl;
    std::cout << "Point on AB (" << edge1.getX() << ", " << edge1.getY()
              << "): " << (bsp(a, b, c, edge1) ? "INSIDE" : "OUTSIDE")
              << std::endl;
    std::cout << "Point on AC (" << edge2.getX() << ", " << edge2.getY()
              << "): " << (bsp(a, b, c, edge2) ? "INSIDE" : "OUTSIDE")
              << std::endl;
    std::cout << "Point on BC (" << edge3.getX() << ", " << edge3.getY()
              << "): " << (bsp(a, b, c, edge3) ? "INSIDE" : "OUTSIDE")
              << std::endl;

    return 0;
}
