#include <iostream>//Write this coding and compile. What is the output?
using namespace std;
int a =90;
namespace myNs//命名空间
{int var1=10;}

namespace myNs
{int var2=20;}

namespace 
{int i=15;int myVar(){return i;}}
int main()
{
int a =60;
cout <<"Value of a = "<<a<< '\n';
cout <<"Value of global a = "<<::a<< '\n';
cout <<"Value of Var1 = "<<myNs::var1<< '\n';
cout <<"Value of Var2 = "<< myNs::var2<< '\n';
cout <<"Value of Var1 = "<<myNs::var1<< '\n';
cout <<"Value returned by unnamed namespacce = "<<myVar()<< '\n';
return 0;
}
// Value of a = 60
// Value of global a = 90
// Value of Var1 = 10
// Value of Var2 = 20
// Value of Var1 = 10
// Value returned by unnamed namespacce = 15
