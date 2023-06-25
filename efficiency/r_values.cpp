#include <iostream>
#include <chrono>

class LargeData {
public:
    LargeData() {
        // Simulate resource-intensive data creation
        std::cout << "Creating LargeData object..." << std::endl;
        data = new int[1000000];
    }

    LargeData(const LargeData& other) {
        // Simulate resource-intensive data copying
        std::cout << "Copying LargeData object..." << std::endl;
        data = new int[1000000];
        std::copy(other.data, other.data + 1000000, data);
    }

    ~LargeData() {
        // Clean up dynamically allocated memory
        delete[] data;
    }

private:
    int* data;
};

void processDataWithRValue(LargeData&& data) {
    // Start the timer
    auto start = std::chrono::high_resolution_clock::now();

    // Do something with the LargeData object
    std::cout << "Processing LargeData object with Rvalue..." << std::endl;

    // Stop the timer and calculate the duration
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    std::cout << "Processing time: " << duration << " microseconds" << std::endl;
}



void processDataWithoutRValue(LargeData data) {
    // Start the timer
    auto start = std::chrono::high_resolution_clock::now();

    // Do something with the LargeData object
    std::cout << "Processing LargeData object without Rvalue..." << std::endl;

    // Stop the timer and calculate the duration
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    std::cout << "Processing time: " << duration << " microseconds" << std::endl;
}

int main() {
    LargeData obj1;  // Create a LargeData object

    processDataWithRValue(std::move(obj1));
    processDataWithoutRValue(obj1);

    return 0;
}