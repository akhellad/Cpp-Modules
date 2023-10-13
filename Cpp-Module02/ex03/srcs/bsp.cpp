#include "../includes/bsp.hpp"

bool bsp(const Point &a, const Point &b, const Point &c, const Point &point) {
    // Calculez les vecteurs représentant les côtés du triangle
    Point ab = b - a;
    Point bc = c - b;
    Point ca = a - c;

    // Calculez les vecteurs reliant les sommets au point
    Point ap = point - a;
    Point bp = point - b;
    Point cp = point - c;

    // Calculez les produits vectoriels
    float cross1 = ab.cross(ap); // Produit vectoriel entre AB et AP
    float cross2 = bc.cross(bp); // Produit vectoriel entre BC et BP
    float cross3 = ca.cross(cp); // Produit vectoriel entre CA et CP

    // Vérifiez la position du point par rapport au triangle
    if ((cross1 >= 0 && cross2 >= 0 && cross3 >= 0) ||
        (cross1 <= 0 && cross2 <= 0 && cross3 <= 0)) {
        // Tous les produits vectoriels ont la même direction
        return true; // Le point est à l'intérieur du triangle
    }

    return false; // Le point est à l'extérieur du triangle
}