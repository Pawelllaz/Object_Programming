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
int my_strcmp(const char *s1, const char *s2)
{
	for(int i = 0; *(s1+i)!='\0' && *(s2+i)!='\0'; i++)
		if(*(s1+i)!=*(s2+i)) return *(s1+i)>*(s2+i) ? 1:-1;
	return 0;
}
int my_strncmp(const char *s1, const char *s2, int n)
{
	for(int i = 0; *(s1+i)!='\0' && *(s2+i)!='\0' && i<n; i++)
		if(*(s1+i)!=*(s2+i)) return *(s1+i)>*(s2+i) ? 1:-1;
	return 0;
}
char *my_strcpy(char *s1, const char *s2)
{
	int i=0;
	for(;*(s2+i)!='\0';i++)
		*(s1+i)=*(s2+i);
	*(s1+i)='\0';
	return s1;
}
char *my_strchr(char *s, int ch)
{
	for(int i=0;*(s+i)!='\0';i++)
		if(*(s+i)==ch) return (s+i);
	return NULL;
}
char *my_strrchr(char *s, int ch)
{
	char *ptr=NULL;
	for(int i=0;*(s+i)!='\0';i++)
		if(*(s+i)==ch) ptr=(s+i);
	return ptr;
}
int my_isalpha(int ch)
{
	return ch>='a' && ch<='z' || ch>='A' && ch<='Z';
}
int my_isupper(int chr){
	return chr >= 'A' && chr <= 'Z';
}

int my_islower(int chr){
	return chr >= 'a' && chr <= 'z';
}

int my_isdigit(int chr){
	return chr >= '0' && chr <= '9';
}

int my_alnum(int chr){
	return chr >= 'a' && chr <= 'z' || chr >= 'A' && chr <= 'Z' || chr >= '0' && chr <= '9';
}

int my_toupper(int chr){
	return chr >= 'a' && chr <= 'z' ? chr + ('A' - 'a') : chr;
}

int my_tolower(int chr){
	return chr >= 'A' && chr <= 'Z' ? chr - ('A' - 'a') : chr;
}
int main()
{
	int (*alp)(int)=my_isalpha;
	cout << alp('g') <<endl;
	char dest[]="abecadlo";
	char src[]="spadlo";
	char *result1,*result2;
	for(int i=0, j=5; i<10 && j<10;i++,j++)
		cout << "i: " << i << "\nj: " << j <<endl;
	result1 = my_strcpy(dest,src);
	cout << result1 <<endl;
	result1 = my_strcat(dest,src);	
	cout << "strcat: " << result1 <<endl;
		
	result2 = my_strncat(dest,src,3);
	cout << "strncat: " << result2 <<endl;
	int a=20;
	printf("%d\n", my_isalpha(a));
		
	return 0;
}
