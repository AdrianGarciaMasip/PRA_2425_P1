#include "Square.h"

// Valida si los vértices forman un cuadrado válido
bool Square::check(Point2D* vertices) {
    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d23 = Point2D::distance(vertices[2], vertices[3]);
    double d30 = Point2D::distance(vertices[3], vertices[0]);

    return (d01 == d12 && d12 == d23 && d23 == d30);
}

// Constructor por defecto
Square::Square()
    : Rectangle("red", new Point2D[N_VERTICES]{
        Point2D(-1, 1), Point2D(1, 1), Point2D(1, -1), Point2D(-1, -1)}) {}

// Constructor parametrizado
Square::Square(std::string color, Point2D* vertices)
    : Rectangle(color, vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Los vértices proporcionados no forman un cuadrado válido.");
    }
}

// Modifica los vértices del cuadrado
void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Los vértices proporcionados no forman un cuadrado válido.");
    }
    Rectangle::set_vertices(vertices);
}

// Sobrescribe el método print
void Square::print() const {
    std::cout << "[Square: color = " << color
              << "; v0 = " << vs[0]
              << "; v1 = " << vs[1]
              << "; v2 = " << vs[2]
              << "; v3 = " << vs[3] << "]";
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& out, const Square& square) {
    square.print();
    return out;
}

