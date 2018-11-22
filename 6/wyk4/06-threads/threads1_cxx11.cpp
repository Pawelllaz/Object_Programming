#include <iostream>
#include <thread>

using namespace std;

void
thread1 (int *p)
{
  cout << "Parameter of thread1: " << *p << endl;
  *p = 1;
  for (unsigned int i = 0; i < 100000; i++)
    cout << "Hello from thread 1\n";
}

void
thread2 (int *p)
{
  cout << "Parameter of thread2: " << *p << endl;
  *p = 2;
  for (unsigned int i = 0; i < 100000; i++)
    cout << "Hello from thread 2\n";
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
