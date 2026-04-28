// ============================================================
// Lab: More Details about Classes
// Course: Object-Oriented Programming (C++)
// Level: 2nd Year Engineering
// Duration: 60 minutes
// ============================================================

#include <iostream>
#include <string>
using namespace std;
// ============================================================
// CLASS DEFINITIONS
// ============================================================

class Point {
private:
    double x;
    double y;
public:
    // TODO 1: Constructor with member initializer list (double x, double y)
    Point(double x, double y) : x(x), y(y) {}

    // TODO 2: const getter for x
    double getX() const { return x; }

    // TODO 3: const getter for y
    double getY() const { return y; }

    // TODO 4: const display()
    void display() const { std::cout << "(" << x << ", " << y << ")"; }

    // TODO 5: declare Rectangle as friend class
    friend class Rectangle;
};


class Rectangle {
private:
    Point topLeft;
    Point bottomRight;
public:
    // TODO 6: constructor with member initializer list
    Rectangle(double x1, double y1, double x2, double y2)
        : topLeft(x1, y1), bottomRight(x2, y2) {}

    // TODO 7: const getWidth()
    double getWidth() const { 
        return bottomRight.getX() - topLeft.getX(); 
    }

    // TODO 8: const getHeight()
    double getHeight() const { 
        return bottomRight.getY() - topLeft.getY(); 
    }

    // TODO 9: const getArea()
    double getArea() const { 
        return getWidth() * getHeight(); 
    }

    // TODO 10: const display()
    void display() const {
        std::cout << "Rectangle: topLeft=";
        topLeft.display();
        std::cout << ", bottomRight=";
        bottomRight.display();
        std::cout << ", area=" << getArea();
    }

    // TODO 11: declare isSameSize as friend function
    friend bool isSameSize(const Rectangle& r1, const Rectangle& r2);
};


// TODO 12: implement isSameSize
bool isSameSize(const Rectangle& r1, const Rectangle& r2) {
    return (r1.getWidth() == r2.getWidth()) && 
           (r1.getHeight() == r2.getHeight());
}


class ConstDemo {
private:
    int value;
public:
    // TODO 13: constructor with member initializer list
    ConstDemo(int v) : value(v) {}

    // TODO 14: const getValue()
    int getValue() const { return value; }

    // TODO 15: NON-const doubleValue() — multiplies value by 2
    void doubleValue() { 
        value *= 2; 
    }

    // TODO 16: const constGetDouble() — returns value * 2 without modifying
    int constGetDouble() const { 
        return value * 2; 
    }
};


// ============================================================
// MAIN
// ============================================================
int main() {
    // TODO 17-21: demo code
    cout << "=== Part 1: Point Demo ===" << endl;
    Point p1(3.5, 4.2);
    Point p2(0, 0);
    
    cout << "Point p1: ";
    p1.display();
    cout << endl;
    cout << "Point p1 x-coordinate: " << p1.getX() << endl;
    cout << "Point p1 y-coordinate: " << p1.getY() << endl;
    
    cout << "\n=== Part 2: Rectangle Demo ===" << endl;
    Rectangle rect1(0, 5, 4, 0);

    cout << "Rectangle 1: ";
    rect1.display();
    cout << endl;
    cout << "Width: " << rect1.getWidth() << endl;
    cout << "Height: " << rect1.getHeight() << endl;
    cout << "Area: " << rect1.getArea() << endl;
    cout << endl;

    cout << "\n=== part 3: Const Member Functions Demo ===" << endl;
    ConstDemo cd1(5);
    const ConstDemo cd2(10);
    
    cout << "cd1 value: " << cd1.getValue() << endl;
    cout << "cd1 doubled (without modifying): " << cd1.constGetDouble() << endl;
    cd1.doubleValue();
    cout << "cd1 after doubleValue(): " << cd1.getValue() << endl;
    
    cout << "\ncd2 (const object) value: " << cd2.getValue() << endl;
    cout << "cd2 doubled: " << cd2.constGetDouble() << endl;
    
    return 0;
}
