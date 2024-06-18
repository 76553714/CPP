#include <iostream>
#include <iomanip> //fixed
//C++ LAB2Q2 
using namespace std;

int main() {
    const double OUNCEStoTON = 35273.92;
    double WeightOunces;

    char repeat;

    do {
        cout << "input the weight(ounces)";
        if(!(cin >> WeightOunces)){cout<<"Invalid!"<<endl;break;}

        double weightMetricTons = WeightOunces / OUNCEStoTON;
        int boxesNeeded = int(OUNCEStoTON / WeightOunces) + 1;

        cout << "The weight is  " << weightMetricTons << " TON" << endl;
        cout << "you need " << boxesNeeded << " cereal box" << endl;

        cout << "Still wanna calculate? \t(Y/N): ";
        cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');

    cout << "\n--END--" << endl;

    return 0;
}
