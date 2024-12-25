#ifndef DRAWING_H
#define DRAWING_H

#include <iostream>
#include "Shape.h"
#include "ListArray.h"

class Drawing {
private:
    List<Shape*>* shapes; // Lista de figuras representadas en el dibujo

public:
    // Constructor
    Drawing();

    // Destructor
    ~Drawing();

    // Métodos
    void add_front(Shape* shape);           // Añade una figura al frente
    void add_back(Shape* shape);            // Añade una figura al fondo
    void print_all();                       // Imprime información de todas las figuras
    double get_area_all_circles();          // Devuelve el área de todos los círculos
    void move_squares(double incX, double incY); // Mueve todos los cuadrados
};

#endif // DRAWING_H

