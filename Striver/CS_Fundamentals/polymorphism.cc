#include <iostream>
#include <vector>

// Define an interface for a vehicle
class Vehicle {
  public:
    // Pure virtual method to start the vehicle
    virtual void start() = 0;

    // Pure virtual method to stop the vehicle
    virtual void stop() = 0;
};

// Define a concrete class for a car, implementing the Vehicle interface
class Car : public Vehicle {
  public:
    // Implement the start method to honk the horn
    void start() override {
      std::cout << "Honk honk! Starting car..." << std::endl;
    }

    // Implement the stop method to turn off the engine
    void stop() override {
      std::cout << "Turning off engine..." << std::endl;
    }
};

// Define a concrete class for a bike, implementing the Vehicle interface
class Bike : public Vehicle {
  public:
    // Implement the start method to kickstart the bike
    void start() override {
      std::cout << "Kickstarting bike..." << std::endl;
    }

    // Implement the stop method to turn off the bike
    void stop() override {
      std::cout << "Turning off bike..." << std::endl;
    }
};

int main() {
  // Create a vector of Vehicle pointers
  std::vector<Vehicle*> vehicles;

  // Add a car and a bike to the vector
  vehicles.push_back(new Car());
  vehicles.push_back(new Bike());

  // Iterate over the vector and start each vehicle
  for (auto v : vehicles) {
    v->start();
  }

  // Iterate over the vector and stop each vehicle
  for (auto v : vehicles) {
    v->stop();
  }

  return 0;
}

/*
In this example, the Vehicle class is an interface, defined with pure virtual methods that must be implemented by concrete classes.
 The Car and Bike classes are concrete classes that implement the Vehicle interface.

We create a vector of Vehicle pointers and add a Car and a Bike to the vector. 
Since both the Car and Bike classes implement the Vehicle interface, we can treat them 
the same way and call their start and stop methods.

This example demonstrates polymorphism, as the Car and Bike objects can be treated as 
Vehicle objects, even though they have different implementations of the start and stop 
methods.
*/