//question:
#include <iostream>  // i. Pre-processor directive

using namespace std;  // ii. Using directive

int main() {  // iii. Main function

    // Declare variables to store the cost and quantity of hamburgers
    double burgerPrice = 5.99;
    int numHamburgers;

    // Ask the user for the number of hamburgers they want to order
    cout << "How many hamburgers would you like to order? ";
    cin >> numHamburgers;

    // Calculate the total cost
    double totalCost = burgerPrice * numHamburgers;  // iv. Arithmetic operator
    cout << "Total cost for " << numHamburgers << " hamburgers: $" << totalCost << endl;

    // Check if the total cost exceeds $20
    if (totalCost > 20.00) {  // v. Comparison operator
        cout << "Your order qualifies for a discount!";
    } else {
        cout << "Enjoy your meal!";
    }

    // The scope of variables: burgerPrice, numHamburgers, and totalCost is limited to this block

    return 0;
}
