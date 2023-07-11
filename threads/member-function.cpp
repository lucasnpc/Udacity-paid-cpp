#include <iostream>
#include <thread>
#include <memory>

class Vehicle
{
public:
    Vehicle() : _id(0) {}
    void addID(int id) { _id = id; }
    void printID()
    {
        std::cout << "Vehicle ID=" << _id << std::endl;
    }
    void setName(std::string name) {
        _name = name;
    };
    void printName() {
        std::cout << "Name " << _name << std::endl;
    }
private:
    int _id;
    std::string _name;
};

int main()
{
    // create thread
    std::shared_ptr<Vehicle> v(new Vehicle);
    std::thread t = std::thread(&Vehicle::addID, v, 1); // call member function on object v

    // TODO: Modify the main to start setName as a thread.
    std::thread tSetName = std::thread(&Vehicle::setName, v, "name");
    // Also, add code to main to print the name of the vehicle.

    // wait for thread to finish
    t.join();
    tSetName.join();

    // print Vehicle id
    v->printID();
    v->printName();
    return 0;
}