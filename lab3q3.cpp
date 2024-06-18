#include <iostream>
#include <vector>
#include <string>
//C++ LAB3Q3 
using namespace std; // Simplifies code by using the std namespace

struct Book //create a BOOK data type with title and availablecopies
{
    string title;
    int availableCopies;
};

int main() {
    vector<Book> library;
    // nitial books information
    library.push_back({"serdang", 5});
    library.push_back({"UPM", 3});
    library.push_back({"china", 7});
    library.push_back({"harrypoter", 2});

    // Display the list of books with available copies
    cout << "Books in the library and their available copies:" << endl;
    for (const Book & book : library) {
        cout << book.title << " - Available Copies: " << book.availableCopies << endl;
    }
    // Prompt the user to enter the title of a book
    string userBookTitle;
    cout << "Enter the title of a book: ";
    cin >> userBookTitle;
    // Check if the book title exists in the library
    bool bookFound = false;
    for (const Book& book : library) 
    {
        if (book.title == userBookTitle) //if found,tell user the amount of copies
        {
            cout << "Available copies for " << userBookTitle << ": " << book.availableCopies << endl;
            bookFound = true;
            break;
        }
            
        
    }
    if(bookFound==false) cout << "The book '" << userBookTitle << "' is not in the library collection." << endl;
    return 0;
}
