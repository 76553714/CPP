#include <iostream>
using namespace std;
// 定义结构体
struct Person 
{
    string name;
    int age;
};
int main() {
    const int arraySize = 3; // 数组的大小
    Person s = {"1",4};
    // 声明一个存储Person结构体实例的数组
    Person people[arraySize];

    std::cout<<s.name<<" "<<s.age<<std::endl;
    // 初始化数组中的结构体实例
    people[0] = {"Alice", 25};
    people[1] = {"Bob", 30};
    people[2] = {"Charlie", 22};

    // 访问数组中的结构体实例并输出信息
    for (int i = 0; i < arraySize; ++i) {
        std::cout << "Person " << i + 1 << ": " << people[i].name << ", " << people[i].age << " years old\n";
    }

    return 0;
}
