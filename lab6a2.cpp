#include <iostream>
using namespace std;
namespace first
{
int myvar = 5;

   namespace second
    {
        namespace third 
        {
        int myvar1=myvar;
        }
    }
}
namespace myalias = first::second::third;
//指向 first::second::third 命名空间。这样可以使用更短的名称引用该嵌套命名空间
namespace demo
{
   int gvar = 300;
}
using namespace demo;
//在demo方法中建变量，然后在全局域使用demo的namespace，从而把局部变量变全局
int main()
{
cout << "Value of global variable in demo namespace = "<<gvar << "\n";
cout << "Value of myvar1 in nested namespace third = "<<myalias::myvar1 << "\n";
return 0;
}

// Value of global variable in demo namespace = 300
// Value of myvar1 in nested namespace third = 5