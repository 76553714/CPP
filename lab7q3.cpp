#include <iostream>
#include <fstream>
//ifstream是文件输入流，用于文件读打开； ofstream是文件输出流，用于文件写打开
//ofstream是从内存到硬盘，ifstream是从硬盘到内存
using namespace std;
int main() {
    // Open a file for writing
    ofstream outFile("lab3output.txt");

    if (!outFile) 
    {
        cerr << "Error opening file for writing." << endl;
        return 1;
    }
    cout << "Enter some text: ";
    string userInput;
    getline(cin, userInput);

    // Write user input to the file
    outFile << userInput << endl;

    // Close the file
    outFile.close();

    // Open the file for reading
    ifstream inFile("lab3output.txt");

    if (!inFile) {cerr << "Error opening file for reading." << endl;return 1;}

    // Read and display the content from the file
    cout << "Content from the file: ";
    string fileContent;
    getline(inFile, fileContent);

    cout << fileContent << endl;

    // Close the file
    inFile.close();

    return 0;
}
