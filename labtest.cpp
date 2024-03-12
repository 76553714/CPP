#include <iostream>// 1. Pre-processor directive: #include <iostream>
using namespace std;// 2. with  Using directive 
void welcome()// 7. Other functions besides the main function: 
{cout<<"welcome,this is a program to calculate carpet cost"<<endl;}

int main() {
    welcome();
    // 3. Data type: double (for carpet length)
    double carpetLength;// 4. Scope of variables: carpetLength is a local variable as it is declared within the main function.
    const double carpetPrice = 3.00;
    const double discountPercentage = 0.15;
    double totalCost;

    cout << "Enter the carpet length in meters: ";
    cin >> carpetLength;
    // 5. Use of operator to solve the problem:
    // 6. Selection/Iteration: 
    if (carpetLength > 10) 
    {totalCost = carpetLength * carpetPrice * (1 - discountPercentage);} 
    else 
    {totalCost = carpetLength * carpetPrice;}
    // 10. Produces correct output: 
    cout << "Total cost of the carpet: $" << totalCost << endl;
    return 0;
}
