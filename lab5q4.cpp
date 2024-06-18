#include <iostream>
#include <string>
using namespace std;
//CPP LAB5 task4 
// Function prototype with declare
void writeProverb(string endWord);

int main() {
    cout << "Given the phrase:" << endl;
    cout << "Now is the time for all good men to come to the aid of their "<< "__" << endl;
    cout << "Input any words you want to end with the sentence: ";
    
    string mainendword;

    cin >> mainendword;

    writeProverb(mainendword);
    return 0;
}

void writeProverb(string endword) 
{
    cout << "Now is the time for all good men to come to the aid of their " << endword << endl;
}
