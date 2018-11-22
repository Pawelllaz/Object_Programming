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
  try {
  c[40]='a';
  } catch (mystring::index_out_of_range&)
  {
    cout << "Index out of range" << endl;
  };
}
