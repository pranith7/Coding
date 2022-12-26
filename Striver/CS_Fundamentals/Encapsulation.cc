#include <iostream>

// Define a class for a car
class Car {
  public:
    // Constructor
    Car(std::string make, std::string model, int year) {
      this->make = make;
      this->model = model;
      this->year = year;
    }

    // Method to start the car
    void start() {
      std::cout << "Starting car..." << std::endl;
    }

    // Method to stop the car
    void stop() {
      std::cout << "Stopping car..." << std::endl;
    }

  private:
    std::string make;
    std::string model;
    int year;
};

int main() {
  // Create a new car object
  Car myCar("Ford", "Mustang", 1969);

  // Start the car
  myCar.start();

  // Stop the car
  myCar.stop();

  return 0;
}

/*

In this example, the Car class represents a car object with three attributes: make, model, and year. 
It also has two methods: start and stop. These methods allow the car to be started and stopped.

To create a new car object, we use the Car constructor, which initializes the attributes of 
the object. We can then use the object's methods to start and stop the car.

This example demonstrates several OOP concepts: encapsulation (data and methods are bundled 
together in the Car class), inheritance (not shown in this example), and polymorphism 
(not shown in this example).
*/