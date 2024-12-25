#include "Rectangle.h"

// Valida si los vértices forman un rectángulo válido
bool Rectangle::check(Point2D* vertices) {
    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d23 = Point2D::distance(vertices[2], vertices[3]);
    double d30 = Point2D::distance(vertices[3], vertices[0]);

    return d01 == d23 && d12 == d30;
}

// Constructor por defecto
Rectangle::Rectangle()
    : Shape(), vs(new Point2D[N_VERTICES]{
        Point2D(-1, 0.5), Point2D(1, 0.5), Point2D(1, -0.5), Point2D(-1, -0.5)}) {}

// Constructor parametrizado
Rectangle::Rectangle(std::string color, Point2D* vertices)
    : Shape(color), vs(new Point2D[N_VERTICES]) {
    if (!check(vertices)) {
        throw std::invalid_argument("Los vértices proporcionados no forman un rectángulo válido.");
    }
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }
}

// Constructor de copia
Rectangle::Rectangle(const Rectangle& r)
    : Shape(r.color), vs(new Point2D[N_VERTICES]) {
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = r.vs[i];
    }
}

// Destructor
Rectangle::~Rectangle() {
    delete[] vs;
}

// Devuelve el vértice en un índice
Point2D Rectangle::get_vertex(int ind) const {
    if (ind < 0 || ind >= N_VERTICES) {
        throw std::out_of_range("Índice fuera de rango.");
    }
    return vs[ind];
}

// Sobrecarga del operador []
Point2D Rectangle::operator[](int ind) const {
    return get_vertex(ind);
}

// Modifica los vértices del rectángulo
void Rectangle::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Los vértices proporcionados no forman un rectángulo válido.");
    }
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }
}

// Sobrecarga del operador de asignación
Rectangle& Rectangle::operator=(const Rectangle& r) {
    if (this != &r) {
        Shape::operator=(r); // Copia el color
        for (int i = 0; i < N_VERTICES; i++) {
            vs[i] = r.vs[i];
        }
    }
    return *this;
}

// Calcula el área del rectángulo
double Rectangle::area() const {
    double width = Point2D::distance(vs[0], vs[1]);
    double height = Point2D::distance(vs[1], vs[2]);
    return width * height;
}

// Calcula el perímetro del rectángulo
double Rectangle::perimeter() const {
    double width = Point2D::distance(vs[0], vs[1]);
    double height = Point2D::distance(vs[1], vs[2]);
    return 2 * (width + height);
}

// Traslada el rectángulo
void Rectangle::translate(double incX, double incY) {
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i].x += incX;
        vs[i].y += incY;
    }
}

// Imprime información del rectángulo
void Rectangle::print() const {
    std::cout << "[Rectangle: color = " << color
              << "; v0 = " << vs[0]
              << "; v1 = " << vs[1]
              << "; v2 = " << vs[2]
              << "; v3 = " << vs[3] << "]";
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& out, const Rectangle& r) {
    r.print();
    return out;
}

