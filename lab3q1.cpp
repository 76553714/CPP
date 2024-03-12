#include <iostream>
#include <vector>
//C++ LAB3Q1
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> evenNumbers;
    vector<int> oddNumbers;

    // Store odd and even numbers into two lists respectively
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            evenNumbers.push_back(arr[i]);
        } else {
            oddNumbers.push_back(arr[i]);
        }
    }

    //Add elements of the odd list to the array
    for (int i = 0; i < oddNumbers.size(); i++) {
        arr[i] = oddNumbers[i];
    }

   //Add elements of the even list to the array
    for (int i = 0; i < evenNumbers.size(); i++) {
        arr[i + oddNumbers.size()] = evenNumbers[i];
    }

    cout << "Reordered array with even numbers before odd numbers: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

