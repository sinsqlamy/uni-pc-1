#include <iostream>
#include <cmath>

class Circle {
private:
    double radius;
public:
    Circle(double r) {
        setRadius(r);
    }
    void setRadius(double r) {
        if (r < 0) {
            throw "Radius cannot be negative";
        }
        radius = r;
    }
    double getRadius() const {
        return radius;
    }
    double getArea() const {
        return M_PI * radius * radius;
    }
};


int main() {
    double r;
    std::cout << "Enter the radius of the circle: ";
    std::cin >> r;
    Circle circle(r);
    std::cout << "The area of the circle is " << circle.getArea() << std::endl;
    return 0;
}
