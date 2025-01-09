#include "Drawing.h"
#include "Circle.h"
#include "Square.h"
#include "Rectangle.h"

Drawing::Drawing() {
    shapes = new ListArray<Shape*>(); // Usa ListArray como implementación de la lista
}

Drawing::~Drawing() {
    for (int i = 0; i < shapes->size(); i++) {
        delete shapes->get(i); // Usa el método get en lugar de []
    }
    delete shapes;
}

// Añade una figura al frente
void Drawing::add_front(Shape* shape) {
    shapes->prepend(shape);
}

// Añade una figura al fondo
void Drawing::add_back(Shape* shape) {
    shapes->append(shape);
}

// Imprime información de todas las figuras
void Drawing::print_all() {
    std::cout << "Drawing contents:" << std::endl;
    for (int i = 0; i < shapes->size(); i++) {
        shapes->get(i)->print(); // Usa el método get en lugar de []
        std::cout << std::endl;
    }
}

// Devuelve el área de todos los círculos
double Drawing::get_area_all_circles() {
    double total_area = 0;
    for (int i = 0; i < shapes->size(); i++) {
        Circle* circle = dynamic_cast<Circle*>(shapes->get(i)); 
        if (circle) {
            total_area += circle->area();
        }
    }
    return total_area;
}

// Mueve todos los cuadrados
void Drawing::move_squares(double incX, double incY) {
    for (int i = 0; i < shapes->size(); i++) {
        Square* square = dynamic_cast<Square*>(shapes->get(i)); 
        if (square) {
            square->translate(incX, incY);
        }
    }
}

