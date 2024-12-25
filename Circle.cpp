#include "Circle.h"

// Constructor por defecto
Circle::Circle() : Shape(), center(Point2D(0, 0)), radius(1) {}

// Constructor parametrizado
Circle::Circle(std::string color, Point2D center, double radius)
    : Shape(color), center(center), radius(radius) {
    if (radius <= 0) {
        throw std::invalid_argument("El radio debe ser mayor que 0.");
    }
}

// Métodos consultores y modificadores
Point2D Circle::get_center() const {
    return center;
}

void Circle::set_center(Point2D p) {
    center = p;
}

double Circle::get_radius() const {
    return radius;
}

void Circle::set_radius(double r) {
    if (r <= 0) {
        throw std::invalid_argument("El radio debe ser mayor que 0.");
    }
    radius = r;
}

// Implementaciones de los métodos virtuales heredados de Shape
double Circle::area() const {
    return M_PI * std::pow(radius, 2);
}

double Circle::perimeter() const {
    return 2 * M_PI * radius;
}

void Circle::translate(double incX, double incY) {
    center.x += incX;
    center.y += incY;
}

void Circle::print() const {
    std::cout << "[Circle: color = " << color
              << "; center = (" << center.x << "," << center.y << ")"
              << "; radius = " << radius << "]" << std::endl;
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& out, const Circle& c) {
    c.print();
    return out;
}

