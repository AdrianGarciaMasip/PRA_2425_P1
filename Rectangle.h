#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stdexcept>
#include <iostream>
#include "Shape.h"
#include "Point2D.h"

class Rectangle : public Shape {
protected:
    Point2D* vs;                      // Puntero a un array de 4 vértices
    static const int N_VERTICES = 4;  // Número de vértices del rectángulo

    // Método privado para validar que los vértices forman un rectángulo
    static bool check(Point2D* vertices);

public:
    // Constructores y destructor
    Rectangle();                                      // Constructor por defecto
    Rectangle(std::string color, Point2D* vertices);  // Constructor con parámetros
    Rectangle(const Rectangle& r);                   // Constructor de copia
    ~Rectangle();                                     // Destructor

    // Métodos consultores y modificadores
    Point2D get_vertex(int ind) const;               // Devuelve el vértice en un índice
    Point2D operator[](int ind) const;               // Sobrecarga del operador []
    virtual void set_vertices(Point2D* vertices);    // Modifica los vértices

    // Sobrecarga del operador de asignación
    Rectangle& operator=(const Rectangle& r);

    // Métodos virtuales heredados de Shape
    double area() const override;                     // Calcula el área del rectángulo
    double perimeter() const override;                // Calcula el perímetro del rectángulo
    void translate(double incX, double incY) override; // Traslada el rectángulo
    void print() const override;                      // Imprime información del rectángulo

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream& out, const Rectangle& r);
};

#endif // RECTANGLE_H

