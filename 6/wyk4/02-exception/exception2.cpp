#include <iostream>
using namespace std;

class myexception{};

class tester
{
  string name;
public:
  tester(const string& n): name(n)
  {
    cout<<name<<"()"<<endl;  
  };
  ~tester()
  {
    cout<<"~"<<name<<"()"<<endl;
  };
};

void f1()
{
  tester f1("f1");
  throw myexception();
  cout << "Exiting f1"<<endl;
}

void f2()
{
  tester f2("f2");
  f1();
  cout << "Exiting f2"<<endl;
}
  
int main()
{
  tester main("main");
  f2();
  return 0;
}
