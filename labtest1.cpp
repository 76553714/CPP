#include <iostream>
using namespace std;
struct Carpet {
    double length;
    const double price = 3.00;
    const double discountPercentage = 0.15;
    };

void welcome() 
{
    cout << "Welcome, this is a program to calculate carpet cost" << endl;
}

int main() {
    welcome();
    int numberOfCarpets;
    cout << "Enter the number of carpets: ";
    cin >> numberOfCarpets;

    // Allocating memory for an array of Carpets
    Carpet *carpets = new Carpet[numberOfCarpets];

    for (int i = 0; i < numberOfCarpets; ++i) {
        cout << "Enter the length of carpet " << i + 1 << " in meters: ";
        cin >> carpets[i].length;
        double totalCost;
         if (carpets[i].length > 10) {
             totalCost = carpets[i].length * carpets[i].price * (1 - carpets[i].discountPercentage);
        } else {
             totalCost = carpets[i].length * carpets[i].price;
        }

        cout << "Total cost of carpet " << i + 1 << ": $" << totalCost << endl;
    }
    delete[] carpets;

    return 0;
}
