#include <iostream>

// Define a base class for a vehicle
class Vehicle {
  public:
    // Constructor
    Vehicle(std::string make, std::string model, int year) {
      this->make = make;
      this->model = model;
      this->year = year;
    }

    // Method to start the vehicle
    virtual void start() {
      std::cout << "Starting vehicle..." << std::endl;
    }

    // Method to stop the vehicle
    virtual void stop() {
      std::cout << "Stopping vehicle..." << std::endl;
    }

  protected:
    std::string make;
    std::string model;
    int year;
};

// Define a subclass for a car, inheriting from the Vehicle class
class Car : public Vehicle {
  public:
    // Constructor
    Car(std::string make, std::string model, int year) :
      Vehicle(make, model, year) { }

    // Override the start method to honk the horn
    void start() override {
      std::cout << "Honk honk! Starting car..." << std::endl;
    }
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
In this example, the Vehicle class represents a base class for a vehicle, 
with three attributes: make, model, and year. It also has two methods: 
start and stop. These methods allow the vehicle to be started and stopped.

The Car class is a subclass of the Vehicle class, which means it inherits all 
of the attributes and methods of the Vehicle class. In addition, it has its own 
implementation of the start method, which honks the horn before starting the car.

This example demonstrates inheritance, as the Car class inherits from the Vehicle 
class and can access its attributes and methods.


*/