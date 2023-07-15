#include <iostream>

class Resource {
public:
    Resource() {
        // Allocate the resource
        data = new int[100];
        std::cout << "Resource created" << std::endl;
    }

    // Transfer ownership to another object
    Resource& operator=(Resource&& other) {
        data = other.data;
        other.data = nullptr;
        std::cout << "Transfering ownership" << std::endl;
        return *this;
    }

    // Use the resource
    void useResource() {
        if (data != nullptr) {
            std::cout << "Resource used" << std::endl;
        }
        else {
            std::cout << "Resource not used" << std::endl;
        }
    }

    ~Resource() {
        if (data != nullptr) {
            delete[] data;
            std::cout << "Resource destroyed" << std::endl;
        }
        else {
            std::cout << "Resource already destroyed" << std::endl;
        }
    }

private:
    int* data;
};

int main() {
    Resource* resource1 = new Resource();
    Resource* resource2 = new Resource();

    resource1->useResource(); // Use resource1

    *resource2 = std::move(*resource1);

    resource1->useResource(); // resource1 is nullptr, cannot use it anymore
    resource2->useResource(); // Use resource2

    delete resource1; // Deleting nullptr is safe
    delete resource2;

    return 0;
}