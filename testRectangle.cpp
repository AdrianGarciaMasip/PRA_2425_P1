#include <iostream>
#include "Rectangle.h"

int main() {
    Rectangle r1;
    Point2D vertices[] = {Point2D(-1, 1), Point2D(1, 1), Point2D(1, -1), Point2D(-1, -1)};
    Rectangle r2("green", vertices);

    std::cout << "r1 = " << r1 << std::endl;
    std::cout << "r1.area() => " << r1.area() << "; r1.perimeter() => " << r1.perimeter() << std::endl;
    std::cout << "r2 = " << r2 << std::endl;
    std::cout << "r2.area() => " << r2.area() << "; r2.perimeter() => " << r2.perimeter() << std::endl;

    return 0;
}

