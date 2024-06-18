#include <iostream>

// Structure to store the range result
struct RangeResult {
    int smallest;
    int largest;
};

// Function prototype
RangeResult range(int* data, int size);

int main() {
    int data[6] = {11, 12, 11, 3, 12, 13};

    // Get the range result
    RangeResult result = range(data, 6);

    // Calculate the range
    int x = result.largest - result.smallest;

    // Output the result
    std::cout << "The range is: " << x << std::endl;

    return 0;
}

RangeResult range(int* data, int size) {
    // Initialize the result structure
    RangeResult result;
    result.smallest = *data;  // Dereference the pointer to get the first element
    result.largest = *data;

    // Loop through the array to find the smallest and largest elements
    for (int i = 1; i < size; ++i) {
        if (*(data + i) < result.smallest) {  // Use pointer arithmetic to access elements
            result.smallest = *(data + i);
        } else if (*(data + i) > result.largest) {
            result.largest = *(data + i);
        }
    }

    return result;
}
