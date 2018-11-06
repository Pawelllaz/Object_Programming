#include <iostream>
using namespace std;
#include <string.h>
#include <ctype.h>

char *my_strcat(char *dest,const char *src)
{
	int i;
	for(i = 0; *(dest+i)!='\0';i++);
	for(int j=0;*(src+j)!='\0';j++)
	{
		*(dest+i++)=*(src+j);
	}
	*(dest+i)='\0';
	return dest;
}
char *my_strncat(char *dest,const char *src, int n)
{
	int i;
	for(i = 0; *(dest+i)!='\0';i++);
	for(int j=0;*(src+j)!='\0' && j<n;j++)
	{
		*(dest+i++)=*(src+j);
	}
	*(dest+i)='\0';
	return dest;	
}
int my_isalpha(int ch)
{
	return ch>='a' && ch<='z' || ch>='A' && ch<='Z';
}
int main()
{
	char dest[]="abecadlo";
	char src[]="spadlo";
	char *result1,*result2;
	
	result1 = my_strcat(dest,src);	
	cout << "strcat: " << result1 <<endl;
		
	result2 = my_strncat(dest,src,3);
	cout << "strncat: " << result2 <<endl;
	int a=20;
	printf("%d\n", my_isalpha(a));
		
	return 0;
}
