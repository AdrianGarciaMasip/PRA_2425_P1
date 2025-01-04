#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <cmath>
#include "Shape.h"

class Circle : public Shape {
private:
    Point2D center; // Centro del círculo
    double radius;  // Radio del círculo

public:
    // Constructores
    Circle(); // Constructor por defecto
    Circle(std::string color, Point2D center, double radius); // Constructor parametrizado

    // Métodos consultores y modificadores
    Point2D get_center() const;
    void set_center(Point2D p);
    double get_radius() const;
    void set_radius(double r);

    // Implementaciones de los métodos virtuales heredados de Shape
    double area() const override;
    double perimeter() const override;
    void translate(double incX, double incY) override;
    void print() const override;

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream& out, const Circle& c);
};

#endif // CIRCLE_H

