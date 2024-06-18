#include <iostream>
#include <cmath>

struct Numbers {
    double num1;
    double num2;
};

double result;

// Function prototypes
void displayMenu();
void getUserInput(int& choice);
void getOperands(Numbers& nums);
void add(const Numbers& nums);
void multiply(const Numbers& nums);
void power(const Numbers& nums);
void squareRoot(const Numbers& nums);
void max(const Numbers& nums);
void displayResult();

int main() {
    int choice;
    Numbers nums;

    do {
        displayMenu();
        getUserInput(choice);

        switch (choice) {
            case 1:
                getOperands(nums);
                add(nums);
                displayResult();
                break;
            case 2:
                getOperands(nums);
                multiply(nums);
                displayResult();
                break;
            case 3:
                getOperands(nums);
                power(nums);
                displayResult();
                break;
            case 4:
                getOperands(nums);
                squareRoot(nums);
                displayResult();
                break;
            case 5:
                getOperands(nums);
                max(nums);
                displayResult();
                break;
            case 6:
                std::cout << "Exiting the program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 6);

    return 0;
}

void displayMenu() {
    std::cout << "Calculator Menu:\n"
              << "1. Add\n"
              << "2. Multiply\n"
              << "3. Power\n"
              << "4. Square Root\n"
              << "5. Max\n"
              << "6. Exit\n"
              << "Enter your choice: ";
}

void getUserInput(int& choice) {
    std::cin >> choice;
}

void getOperands(Numbers& nums) {
    std::cout << "Enter the first operand: ";
    std::cin >> nums.num1;
    std::cout << "Enter the second operand: ";
    std::cin >> nums.num2;
}

void add(const Numbers& nums) {
    result = nums.num1 + nums.num2;
}

void multiply(const Numbers& nums) {
    result = nums.num1 * nums.num2;
}

void power(const Numbers& nums) {
    result = std::pow(nums.num1, nums.num2);
}

void squareRoot(const Numbers& nums) {
    result = std::sqrt(nums.num1);
}

void max(const Numbers& nums) {
    result = (nums.num1 > nums.num2) ? nums.num1 : nums.num2;
}

void displayResult() {
    std::cout << "Result: " << result << std::endl;
}
