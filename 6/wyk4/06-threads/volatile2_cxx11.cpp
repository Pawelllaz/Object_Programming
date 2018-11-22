#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

volatile int val = 0;

void
fun1 ()
{
  val = 0;
  while (1)
    if (val != 0)
      break;
  printf ("out of the loop\n");
}

int
main ()
{
  thread w = thread(fun1);
  sleep(1);
  val = 1;
  w.join ();
}
