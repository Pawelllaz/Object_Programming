#include <iostream>
using namespace std;
#include "vector.h"

template<class C> void printvector (vector<C>  v)
{
  cout << v << endl;
};

int
main ()
{
  vector<int> a (10);
  cout << a << endl;
  a[0] = 15;
  a[5] = 32;
  vector<int> b(10);
  b=a;
  printvector (b);
  vector<string> c(10);
  vector<string> d(15);
  c[0]="ala";
  c[9]="ma kota";
  d=c;
  printvector(d);
};
