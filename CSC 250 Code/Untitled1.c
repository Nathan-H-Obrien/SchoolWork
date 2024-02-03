#include <iostream>
using namespace std;
class TestClass
{
public:
TestClass(int x)
{ cout << x << endl; }
TestClass()
{ cout << "Hello!" << endl; }
};
int main()
{
TestClass test;
return 0;
}
