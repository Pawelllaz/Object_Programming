#include <iostream>
#include <memory>
using namespace std;


void f1()
{
  int *a = new int[500000000];
  delete [] a;
}

void f2()
{
  f1();
}
  
int main()
{
try {
  f2();
}
catch(bad_alloc&) {
  cout << "bad_alloc"<<endl;
}
  return 0;
}
