#include <iostream>
#include <vector>
#include <algorithm>
//Lab3q2 
using namespace std;

int main() {
    vector<int> numbers;
    int n; //amount of elements
    
    cout << "Enter the number of elements: ";
    cin >> n;

    if (n < 2) //when elements are not enought
    {
        cout << "Vector contains less than two elements. Unable to find second smallest and second largest." << endl;
        return 1;
    }

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        numbers.push_back(num);
    }

    sort(numbers.begin(), numbers.end());//sort from small to big
    
    int secondSmallest = numbers[1]; //second small
    int secondLargest = numbers[numbers.size() - 2]; //second big

    cout << "Second smallest element: " << secondSmallest << endl;
    cout << "Second largest element: " << secondLargest << endl;

    return 0;
}
