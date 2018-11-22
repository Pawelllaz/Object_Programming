#include <iostream>
#include <thread>

#include <string>

using namespace std;

string s (STRING);

void
thread1 (int *p)
{
  cout << "Parameter of thread1: " << *p << endl;
  *p = 1;
  for (unsigned int i = 0; i < COUNT; i++)
    {
      string s1 (s);
    }
}

void
thread2 (int *p)
{
  cout << "Parameter of thread2: " << *p << endl;
  *p = 2;
  for (unsigned int i = 0; i < COUNT; i++)
    {
      string s1 (s);
    }
} 


int
main ()
{
  thread t1;
  thread t2;
  int r1 = 10, r2 = 11;


  t1 = thread (thread1, &r1);
  t2 = thread (thread2, &r2);

  t1.join();
  t2.join();
}
