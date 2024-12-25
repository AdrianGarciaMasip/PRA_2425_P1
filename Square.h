#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include "Rectangle.h"

class Square : public Rectangle {
private:
    // Valida si los vértices forman un cuadrado válido
    static bool check(Point2D* vertices);

public:
    // Constructores
    Square();                                       // Constructor por defecto
    Square(std::string color, Point2D* vertices);  // Constructor parametrizado

    // Sobrescribe el método virtual set_vertices de Rectangle
    void set_vertices(Point2D* vertices) override;

    // Sobrescribe el método virtual print de Rectangle
    void print() const override;

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream& out, const Square& square);
};

#endif // SQUARE_H

