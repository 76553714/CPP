#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Open a file for writing
    ofstream outFile("lab3output.txt", ios::app);  // Change: append to existing file

    if (!outFile) {
        cerr << "Error opening file for writing." << endl;
        return 1;
    }

    cout << "Enter more text: ";  // Change: prompt user for additional input
    string userInput;
    getline(cin, userInput);

    // Write user input to the file
    outFile << userInput << endl;

    // Close the file
    outFile.close();

    // Open the file for reading
    ifstream inFile("lab3output.txt");

    if (!inFile) {
        cerr << "Error opening file for reading." << endl;
        return 1;
    }

    // Read and display the content from the file
    cout << "Updated content from the file: ";
    string fileContent;
    getline(inFile, fileContent);

    cout << fileContent << endl;

    // Close the file
    inFile.close();

    return 0;
}
