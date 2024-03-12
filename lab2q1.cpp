#include <iostream>
// C++ LAB2Q1 
using namespace std;

int main() {
    double x;
    cout << "Enter a value for x: ";
    cin >> x;

    double result = x * x - x - 2;

    bool isPositive = result > 0;

    if (isPositive) {
        cout << "The quadratic expression is positive for x = " << x << std::endl;
    } else {
        cout << "The quadratic expression is not positive for x = " << x << std::endl;
    }

    return 0;
}
