// Grades.cpp
// This program reads records from a file. The file contains the
// following: student�s name, two test grades and final exam grade.
// It then prints this information to the screen.

#include <fstream>  // FILL IN DIRECTIVE FOR FILES
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

const int NAMESIZE = 15;
const int MAXRECORDS = 50;

struct Grades // declares a structure
{
    char name[NAMESIZE + 1];
    int test1;
    int test2;
    int final;
    char letter;
};

typedef Grades gradeType[MAXRECORDS];
// This makes gradeType a data type
// that holds MAXRECORDS
// Grades structures.

// FIll IN THE CODE FOR THE PROTOTYPE OF THE FUNCTION ReadIt
// WHERE THE FIRST ARGUMENT IS AN INPUT FILE, THE SECOND IS THE
// ARRAY OF RECORDS, AND THE THIRD WILL HOLD THE NUMBER OF RECORDS
// CURRENTLY IN THE ARRAY.
void readIt(ifstream& inData, gradeType gradeRec, int& total);
char calculateLetterGrade(int average);

int main()
{
    ifstream indata;
    indata.open("graderoll.dat");

    int numRecord; // number of records read in
    gradeType studentRecord;

    if (!indata)
    {
        cout << "Error opening file. \n";
        cout << "It may not exist where indicated" << endl;
        return 1;
    }
    // FILL IN THE CODE TO CALL THE FUNCTION ReadIt.
    readIt(indata, studentRecord, numRecord);

    cout << "Name" << setw(20)
        << "Test 1" << setw(10)
        << "Test 2" << setw(10)
        << "Final" << setw(10)
        << "Grade" << endl;

    // output the information
    for (int count = 0; count < numRecord; count++)
    {
        // Calculate the average
        int average = (studentRecord[count].test1 * 0.3) +
                      (studentRecord[count].test2 * 0.3) +
                      (studentRecord[count].final * 0.4);

        // Calculate and assign the letter grade
        studentRecord[count].letter = calculateLetterGrade(average);

        cout << studentRecord[count].name << setw(10)
             << studentRecord[count].test1 << setw(10)
             << studentRecord[count].test2 << setw(10)
             << studentRecord[count].final << setw(10)
             << studentRecord[count].letter << endl;
    }

    indata.close();
    return 0;
}

//**************************************************************
// readIt
//
// task: This procedure reads records into an array of
// records from an input file and keeps track of the
// total number of records
// data in: data file containing information to be placed in
// the array
// data out: an array of records and the number of records
//
//**************************************************************

void readIt(ifstream& inData, gradeType gradeRec, int& total)
{
    total = 0;
    inData.get(gradeRec[total].name, NAMESIZE);

    while (inData)
    {
        // FILL IN THE CODE TO READ test1
        inData >> gradeRec[total].test1;

        // FILL IN THE CODE TO READ test2
        inData >> gradeRec[total].test2;

        // FILL IN THE CODE TO READ finals
        inData >> gradeRec[total].final;

        total++; // add one to total

        // FILL IN THE CODE TO CONSUME THE END OF LINE
        inData.ignore(numeric_limits <streamsize>::max(), '\n');

        // FILL IN THE CODE TO READ name
        inData.get(gradeRec[total].name, NAMESIZE);
    }
}

char calculateLetterGrade(int average)
{
    if (average >= 90)
        return 'A';
    else if (average >= 80)
        return 'B';
    else if (average >= 70)
        return 'C';
    else if (average >= 60)
        return 'D';
    else
        return 'F';
}
