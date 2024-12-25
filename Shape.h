#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <stdexcept>
#include "Point2D.h"

class Shape {
protected:
    std::string color; // Color de la figura: "red", "green", "blue"

public:
    // Constructores
    Shape();                      // Constructor por defecto
    Shape(std::string color);     // Constructor con validación de color

    // Métodos de acceso y modificación
    std::string get_color() const; // Devuelve el color
    void set_color(std::string c); // Modifica el color con validación

    // Métodos virtuales puros
    virtual double area() const = 0;        // Calcula el área de la figura
    virtual double perimeter() const = 0;  // Calcula el perímetro de la figura
    virtual void translate(double incX, double incY) = 0; // Traslada la figura
    virtual void print() const = 0;        // Imprime información básica de la figura

    // Destructor virtual
    virtual ~Shape() = default;
};

#endif // SHAPE_H

