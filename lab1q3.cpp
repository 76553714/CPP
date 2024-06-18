#include <iostream>
#include <iomanip>  
using namespace std;
//LAB1Q3 
int main() {
    
    double a4Price = 10.00;
    double pencilPrice = 23.50;
    double sprayerPrice = 14.75;

    short a4Quantity = 0;
    short pencilQuantity = 0;
    short sprayerQuantity = 0;
    double totalSales = 0.0;

    char choice;

    std::cout << "The AZ Shop sells the following gardening tools and plants:" << std::endl;
    std::cout << "Item\t\t\tPrice Per Unit" << std::endl;
    std::cout << "A4 Paper\t\t$ " << std::fixed << std::setprecision(2) << a4Price << std::endl;
    std::cout << "Colour Pencil\t\t$ " << std::fixed << std::setprecision(2) << pencilPrice << std::endl;
    std::cout << "Sprayer\t\t\t$ " << std::fixed << std::setprecision(2) << sprayerPrice << std::endl;

   
    while (true) {
        std::cout << "Enter the item code (A for A4 Paper, C for Colour Pencil, S for Sprayer, or Q to quit): ";
        std::cin >> choice;

        if (choice == 'Q') {
            break;  
        }

        int quantity;
        switch (choice) {
            case 'A':
                std::cout << "Enter the number of A4 Paper that you want to buy: ";
                std::cin >> quantity;
                a4Quantity += quantity;
                break;
            case 'C':
                std::cout << "Enter the number of Colour Pencil that you want to buy: ";
                std::cin >> quantity;
                pencilQuantity += quantity;
                break;
            case 'S':
                std::cout << "Enter the number of Sprayers that you want to buy: ";
                std::cin >> quantity;
                sprayerQuantity += quantity;
                break;
            default:
                std::cout << "Invalid item code. Please try again." << std::endl;
        }
    }


    double totalA4Sales = a4Price * a4Quantity;
    double totalPencilSales = pencilPrice * pencilQuantity;
    double totalSprayerSales = sprayerPrice * sprayerQuantity;
    totalSales = totalA4Sales + totalPencilSales + totalSprayerSales;

    std::cout << "The total sales of AZ Shop" << std::endl;
    std::cout << "$" << std::fixed << std::setprecision(2) << totalSales << std::endl;
    std::cout << "The total sales of A4 Paper $" << std::fixed << std::setprecision(2) << totalA4Sales << std::endl;
    std::cout << "The total sales of Colour Pencil $" << std::fixed << std::setprecision(2) << totalPencilSales << std::endl;
    std::cout << "The total sales of Sprayer $" << std::fixed << std::setprecision(2) << totalSprayerSales << std::endl;

    return 0;
}
