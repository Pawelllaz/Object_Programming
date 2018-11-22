#include <string.h>
#include <iostream>
using namespace std;
#include "mystring.h"

int main()
{
  mystring a("ala");
  mystring b=a;
  b[0]='c';
  cout << b << endl;
  mystring c=a+b;
  c+="ola";
  cout << c+"ula"<<endl;
  mystring d;
  cout << strlen(d)<<endl;
}
