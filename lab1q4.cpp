#include<iostream>
using namespace std;
//LAB1Q4 
int main()
{
string code;
    while (code!="4")
    {
    cout<<"option \t output"<<endl;
    cout<<"1\tCheck out a book"<<endl;
    cout<<"2\tReturn a book"<<endl;
    cout<<"3\tView available books"<<endl;
    cout<<"4\tEXIT"<<endl;
    cout<<"Enter your option(1-4)"<<endl;
    cin>>code;

    switch (stoi(code))
    {
    case 1:cout<<"--Check out a book--"<<endl;
        break;
    case 2:cout<<"--Return a book--"<<endl;
        break;
    case 3:cout<<"--View available books--"<<endl;
        break;
    case 4:cout<<"--EXIT--"<<endl;
        break;
    default:cout<<"Invalid option"<<endl;
    }

    }
    
    
    cout<<"Thank you for using our library"<<endl;
    return 0 ;

}