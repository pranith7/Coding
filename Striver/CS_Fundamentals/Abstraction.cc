#include <iostream>

// Define an abstract class for a shape
class Shape {
  public:
    // Pure virtual method to compute the area of the shape
    virtual double area() = 0;

    // Pure virtual method to compute the perimeter of the shape
    virtual double perimeter() = 0;
};

// Define a concrete class for a circle, inheriting from the Shape class
class Circle : public Shape {
  public:
    // Constructor
    Circle(double radius) {
      this->radius = radius;
    }

    // Implement the area method
    double area() override {
      return 3.14 * radius * radius;
    }

    // Implement the perimeter method
    double perimeter() override {
      return 2 * 3.14 * radius;
    }

  private:
    double radius;
};

int main() {
  // Create a new circle object
  Circle myCircle(10);

  // Print the area and perimeter of the circle
  std::cout << "Area: " << myCircle.area() << std::endl;
  std::cout << "Perimeter: " << myCircle.perimeter() << std::endl;

  return 0;
}
/*
In this example, the Shape class is an abstract class, defined with pure virtual
 methods that must be implemented by concrete classes. 

The Circle class is a concrete class that inherits from the Shape class and 
implements the area and perimeter methods.

We can create an object of the Circle class and call its area and perimeter methods, 
but we cannot create an object of the Shape class, since it is an abstract class. 

This allows us to expose only the necessary information (the area and perimeter methods) 
to the outside world, while hiding the implementation details (how the area and perimeter 
are computed) within the Circle class.

This example demonstrates abstraction, as the Shape class provides a high-level interface 
for working with shapes, while the implementation details are hidden within the Circle class.
*/