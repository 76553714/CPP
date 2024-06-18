#include <iostream>

int sum2D(int array[][4], int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum += array[i][j];
        }
    }
    return sum;
}

int main() {
    int array[3][4] = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};
    std::cout << "Sum of 2D array: " << sum2D(array, 3, 4) << std::endl;
    return 0;
}
