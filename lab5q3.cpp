#include <iostream>
#include <string>
using namespace std;
//CPP LAB5Q3 
// Function prototype with declare
void writeProverb(const string endWord);

int main() {
    cout << "Given the phrase:" << endl;
    cout << "Now is the time for all good men to come to the aid of their "<< "__" << endl;
    cout << "Input a 1 if you want the sentence to be finished with party" << endl;
    cout << "Input a 2 if you want the sentence to be finished with country" << endl;
    cout << "Please input your choice now: ";

    int choice;
    cin >> choice;
    // If the user chooses 1, print "party"; if 2, print "country"; otherwise, ask for a new choice
    if (choice == 1) {writeProverb(" party");}
    else if (choice == 2) {writeProverb(" country");}
    else {cout << "Incorrect choice.input a 1 or 2." << endl;}
    
    return 0;
}

void writeProverb(const string endword) 
{
    cout << "Now is the time for all good men to come to the aid of their" << endword << endl;
}
