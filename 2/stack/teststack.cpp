#include <stdio.h>
#include "stack.h"

int main()
{
	stack s1;
	stack s2;
	s1.display();
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s2.push(5);
	s2.push(6);
	s1.push(7);
	s1.push(8);
	s1.push(9);
	s2.push(10);
	s2.push(11);
	s1.display();
	s2.display();
	printf("pop1: %d\npop2: %d\n", s1.pop(),s2.pop());
	s1.display();
	s2.display();
	s1.clear();
	printf("czyszczenie pierwszego stosu\n");
	s1.display();
	s2.display();
	return 0;
}
