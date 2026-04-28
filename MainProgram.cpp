// ============================================================
// Lab: More Details about Classes
// Course: Object-Oriented Programming (C++)
// Level: 2nd Year Engineering
// Duration: 60 minutes
// ============================================================

#include <iostream>
#include <string>
#include <cmath>  // For fabs() if needed, but we'll use absolute value

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
    void display() const { cout << "(" << x << ", " << y << ")"; }

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

    // TODO 7: const getWidth() - ALWAYS return positive width
    double getWidth() const { 
        // Use absolute value to handle reversed coordinates
        double width = bottomRight.getX() - topLeft.getX();
        return (width >= 0) ? width : -width;
    }

    // TODO 8: const getHeight() - ALWAYS return positive height
    double getHeight() const { 
        // Use absolute value to handle reversed coordinates
        double height = bottomRight.getY() - topLeft.getY();
        return (height >= 0) ? height : -height;
    }

    // TODO 9: const getArea()
    double getArea() const { 
        return getWidth() * getHeight(); 
    }

    // TODO 10: const display()
    void display() const {
        cout << "Rectangle: topLeft=";
        topLeft.display();
        cout << ", bottomRight=";
        bottomRight.display();
        cout << ", area=" << getArea();
    }

    // TODO 11: declare isSameSize as friend function
    friend bool isSameSize(const Rectangle& r1, const Rectangle& r2);
};


// TODO 12: implement isSameSize - compare areas, not dimensions
bool isSameSize(const Rectangle& r1, const Rectangle& r2) {
    // Compare areas (which already use absolute values)
    // Use a small epsilon for floating point comparison
    double area1 = r1.getArea();
    double area2 = r2.getArea();
    
    // Check if areas are approximately equal (within 0.0001 tolerance)
    return (area1 - area2 < 0.0001) && (area2 - area1 < 0.0001);
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
    // Point Demo
    cout << "=== Part 1: Point Demo ===" << endl;
    Point p1(3.5, 4.2);
    Point p2(0, 0);
    
    cout << "Point p1: ";
    p1.display();
    cout << endl;
    cout << "Point p1 x-coordinate: " << p1.getX() << endl;
    cout << "Point p1 y-coordinate: " << p1.getY() << endl;
    cout << endl;
    
    // (Group B)
    cout << "=== Part 2: Rectangle Demo ===" << endl;
    Rectangle rect1(0, 5, 4, 0);
    Rectangle rect2(1, 3, 5, 1);
    Rectangle rect3(0, 6, 3, 2);
    Rectangle rect4(4, 0, 0, 3);
    
    cout << "Rectangle 1: ";
    rect1.display();
    cout << endl;
    cout << "Width: " << rect1.getWidth() << endl;
    cout << "Height: " << rect1.getHeight() << endl;
    cout << "Area: " << rect1.getArea() << endl;
    
    cout << "\nRectangle 2: ";
    rect2.display();
    cout << endl;
    cout << "Width: " << rect2.getWidth() << endl;
    cout << "Height: " << rect2.getHeight() << endl;
    cout << "Area: " << rect2.getArea() << endl;
    
    cout << "\nRectangle 3: ";
    rect3.display();
    cout << endl;
    cout << "Width: " << rect3.getWidth() << endl;
    cout << "Height: " << rect3.getHeight() << endl;
    cout << "Area: " << rect3.getArea() << endl;
    
    cout << "\nRectangle 4 (reversed coordinates): ";
    rect4.display();
    cout << endl;
    cout << "Width: " << rect4.getWidth() << " (should be positive 4)" << endl;
    cout << "Height: " << rect4.getHeight() << " (should be positive 3)" << endl;
    cout << endl;
    
    // (Group C)
    cout << "=== Part 3: Friend Function Demo ===" << endl;
    cout << "Rect1 and Rect2 same size? " << boolalpha 
         << isSameSize(rect1, rect2) << endl;
    cout << "Rect1 and Rect3 same size? " 
         << isSameSize(rect1, rect3) << endl;
    cout << "Rect2 and Rect3 same size? " 
         << isSameSize(rect2, rect3) << endl;
    
    // Test zero-area rectangles
    Rectangle zeroRect1(0, 0, 0, 5);  // Width = 0
    Rectangle zeroRect2(2, 2, 2, 7);  // Width = 0
    cout << "\nZero-area rectangles same size? " 
         << isSameSize(zeroRect1, zeroRect2) << " (should be true)" << endl;
    cout << endl;
    
    // (Group D)
    cout << "=== Part 4: Const Member Functions Demo ===" << endl;
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
