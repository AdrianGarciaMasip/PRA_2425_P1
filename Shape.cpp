#include "Shape.h"
#include <stdexcept>

// Constructor por defecto
Shape::Shape() {
    color = "red";
}

// Constructor con validación de color
Shape::Shape(std::string color) {
    if (color == "red" || color == "green" || color == "blue") {
        this->color = color;
    } else {
        throw std::invalid_argument("Color no válido. Debe ser 'red', 'green' o 'blue'.");
    }
}

// Devuelve el color
std::string Shape::get_color() const {
    return color;
}

// Modifica el color con validación
void Shape::set_color(std::string c) {
    if (c == "red" || c == "green" || c == "blue") {
        color = c;
    } else {
        throw std::invalid_argument("El color no es válido. Debe ser 'red', 'green' o 'blue'.");
    }
}

