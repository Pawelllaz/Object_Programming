#include <stdio.h>
#include "mystring.h"

string s ("ala");

void *
thread1 (void *p)
{
  int *pp = (int *) p;
  printf ("Parameter of thread1: %d\n", *pp);
  *pp = 1;
  for (unsigned int i = 0; i < 100000; i++)
    {
      string s1 (s);
    }
  pthread_exit (p);
}

void *
thread2 (void *p)
{
  int *pp = (int *) p;
  printf ("Parameter of thread2: %d\n", *pp);
  *pp = 2;
  for (unsigned int i = 0; i < 100000; i++)
    {
      string s1 (s);
    }
  pthread_exit (p);
}


int
main ()
{
  pthread_t t1;
  pthread_t t2;
  int *retval1;
  int *retval2;
  int r1 = 10, r2 = 11;


  pthread_create (&t1, NULL, thread1, &r1);
  pthread_create (&t2, NULL, thread2, &r2);

  pthread_join (t1, (void **) &retval1);
  pthread_join (t2, (void **) &retval2);

  printf ("%d\n", *retval1);
  printf ("%d\n", *retval2);
}
