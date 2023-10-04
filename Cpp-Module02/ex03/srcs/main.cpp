#include <iostream>
#include "../includes/Point.hpp"
#include "../includes/bsp.hpp"

int main() {
    Point a(0.0f, 0.0f);
    Point b(4.0f, 0.0f);
    Point c(0.0f, 3.0f);
    Point p1(2.0f, 1.5f); // À l'intérieur du triangle
    Point p2(5.0f, 5.0f); // À l'extérieur du triangle
    Point p3(0.0f, 0.0f); // Sur un sommet du triangle

    std::cout << "p1 is inside triangle: " << bsp(a, b, c, p1) << std::endl; // Devrait afficher true
    std::cout << "p2 is inside triangle: " << bsp(a, b, c, p2) << std::endl; // Devrait afficher false
    std::cout << "p3 is inside triangle: " << bsp(a, b, c, p3) << std::endl; // Devrait afficher false

    return 0;
}
