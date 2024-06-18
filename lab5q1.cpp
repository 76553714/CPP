#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
// Function to display the beverage menu and get user input
int getChoice() //无参有反
{
    cout<<"Choose 1, 2, 3, 4 from the above menu,-1 to exit"<<endl;
    int choice; cin >> choice;  return choice;
}

// Function to perform survey tally
void surveyTally(vector<int>& tally) 
{
    int person = 1;
    int choice;
    while (true) {
        cout << "Enter favorite beverage of person #" << person << ": ";
        choice = getChoice(); //get the choice from the functoion

        if (choice == -1) 
            {break;}
            else if (choice >= 1 && choice <= 4) 
            {tally[choice - 1]++;person++;} //add a count person
        else 
            {cout << "Invalid choice.Choose between 1 and 4"<<endl;}
    }
}
// Function to display survey results
void displayResults(const vector<int>& tally) {
    cout << "Total number of people surveyed is " << tally.size() << ". The results are as follows:" << endl;

    string beverages[] = {"Coffee", "Tea", "Coke", "Orange Juice"};

    for (int i = 0; i < 4; ++i) 
    {
        cout<<setw(15)<<left<<beverages[i]<<tally[i] << endl;//bv name + numbers of vote
        //fix 15 position 左对齐
    }
}

int main() 
{
    vector<int> tally(4, 0); //4 elements with inisitial 0
    surveyTally(tally); //counting number of people
    displayResults(tally);
    return 0;
}
