#include <iostream>
#include <fstream>
using namespace std;

struct Employee 
{
    int hours;
    double payRate;
    double stateTax;
    double fedTax;// 联邦税
};

// 计算净收入的函数
double calculateNetPay(const Employee& emp) 
{
    double grossPay = emp.hours * emp.payRate;
    double totalTax = grossPay * (emp.stateTax + emp.fedTax);
    return grossPay - totalTax;
}

int main() {
    ifstream datainFile("employee_data.txt");

    if (!datainFile) 
    {
        cerr << "Error opening file." << endl;
        return 1;
    }

    Employee employee;
    // 从文件中读取数据，计算净收入并输出结果
    while (datainFile >> employee.hours >> employee.payRate >> employee.stateTax >> employee.fedTax) 
    {
        double netPay = calculateNetPay(employee);
        cout << "Net pay for employee: $" << netPay << endl;
        //同时把输出结果保存到output.txt
        ofstream outfile("output.txt", ios::app);
        outfile << "Net pay for employee: $" << netPay << endl;
        outfile.close();
    }
    cout<<"result has been saved to output.txt";
    datainFile.close();
    return 0;
}
// Net pay for employee: $498
// Net pay for employee: $420
// Net pay for employee: $615