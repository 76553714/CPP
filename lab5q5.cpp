#include <iostream>
using namespace std;
// CPP lab5q4 
double calculateAverage(int GradeAmount,int sum);
int main() 
{
    cout << "Enter the amount of grades: ";
    int GradeAmount;    cin >> GradeAmount;
    // Validate input for a positive number of grades
    while (GradeAmount <= 0) 
    {
        cout << "Please enter a positive number of grades: ";
        cin >> GradeAmount;
    }

    double sum = 0;
    double grade;

    // Get each grade from the user and calculate the sum
    for (int i = 1; i <= GradeAmount; ++i) 
    {
        cout << "Enter a numeric grade between 0-100: ";
        cin >> grade;

        // Validate input for grades in the valid range
        while (grade < 0 || grade > 100) 
        {
        cout << "ERROR INPUT! MUST between 0-100: ";
        cin >> grade;
        }

        sum += grade;
    }

    // Calculate the average by calling the function
    double average=calculateAverage(GradeAmount, sum);

    // Determine the letter grade based on the 10-point scale
    char GradeChar;
    if (average >= 90) {GradeChar = 'A';}
    else if (average >= 80) {GradeChar = 'B';}
    else if (average >= 70) {GradeChar = 'C';}
    else if (average >= 60) {GradeChar = 'D';}
    else {GradeChar = 'F';}
    // Output the result
    cout<<"average is "<<average<<endl;
    cout << "The grade is " << GradeChar << endl;
    return 0;
}

// Function to calculate the average
double calculateAverage(int GradeAmount,int sum) 
{
    double average;
    average = sum / GradeAmount;
    return average;
}
