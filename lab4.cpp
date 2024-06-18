#include <iostream>
#include <iomanip>  // for setprecision
using namespace std;

// C++ LAB4
// Question: Define a struct array to record the information for all fast food in your fast-food shop

int main()
{
    struct fooditem
    {
        char code;       // item code of food
        string name;
        double price;
        bool delivery;  // can take away or not
        int calories;
    };

    fooditem menu[5];  // number of menu items
    menu[0] = {'C', "Chicken", 3, true, 4850};
    menu[1] = {'B', "BeefSoup", 1.5, false, 900};
    menu[2] = {'S', "Sprite+", 1.25, true, 900};
    menu[3] = {'I', "IceCream", 2, false, 1200};
    menu[4] = {'H', "Hotdog", 0.5, true, 1500};

    char option;
    cout << "Select an option (A for dine-in, B for take-away): ";
    cin >> option;
    if(option!='A' && option!='B') {cout<<"menu version not found,now exit!";return 0;}
    cout << "Menu:" << endl;
    cout << "Code\tName\t\tPrice\tDelivery\tCalories" << endl;

    // Display only items available for delivery if the option is take-away
    for (int i = 0; i < 5; ++i)
    {
        if (option == 'A' || (option == 'B' && menu[i].delivery))
        {
            cout << menu[i].code << "\t" << menu[i].name << "\t\t" << menu[i].price << "\t" << menu[i].delivery << "\t\t" << menu[i].calories << endl;
        }
        
    }

    char foodCode;
    int quantity;
    double totalPrice = 0;

    cout << "Enter the food code and quantity (For example: C 2): ";
    cin >> foodCode >> quantity;
    bool found=false;
    // Calculate total price and display the result
    for (int i = 0; i < 5; ++i)
    {
        if (foodCode == menu[i].code)
        {totalPrice = quantity * menu[i].price;found=true;break;}  
    }
    if (found==false){cout<<"Item not found so exit,Please check our menu";exit(0);}

    cout << "Total Price: $" << fixed << setprecision(2) << totalPrice << endl;
    cout << "Quantity: " << quantity << endl;

    return 0;
}
