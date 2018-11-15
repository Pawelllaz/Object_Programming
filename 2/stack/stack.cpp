#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

stack::stack()
{
	this->top = 0;
	this->dane = (int*)malloc(sizeof(int) * 2);
	this->capacity = 2;
}

stack::~stack()
{
	free(dane);
}

void stack::clear()
{
	this->capacity=0;
	this->top = 0;

	free(this->dane);
	this->dane=NULL;
}

int stack::push(int a)
{
	int *temp;
	if (this->top >= this->capacity)
	{
		temp=(int*)realloc(this->dane, (sizeof(int)*this->top) * 2);
		if(temp==NULL)
		{
			printf("blad alokacji pamieci");
			return 2;
		}
		else this->dane=temp;	
		this->capacity *= 2;
	}
	this->dane[this->top] = a;
	this->top++;
	return 0;
}
int stack::pop()
{
	if (this->top < 1)
	{
		printf("stos pusty");
		return -1;
	}
	return this->dane[--this->top];
}
void stack::display()
{
	if (this->top > 0)
	{
		for (int i = 0; i < this->top; i++)
		{
			printf("%d ", this->dane[i]);
		}
		printf("\n");
	}
	else printf("stos pusty\n");
}
