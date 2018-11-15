#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* my_strcat(char *str1, char *str2);

int main()
{
	char *str1=(char*)malloc(20);
	if(str1==NULL)
	{
		printf("blad alokacji pamieci\n");
		return 1;
	}	
	char *str2=(char*)malloc(20);
	if(str2==NULL)
	{
		printf("blad alokacji pamieci\n");
		free(str1);
		return 2;
	}
	printf("wpisz pierwszy wyraz: ");	
	scanf("%s", str1);
	printf("wpisz drugi wyraz: ");	
	scanf("%s", str2);
	char *str3;
	str3=my_strcat(str1,str2);
	if(str3==NULL)
	{
		printf("blad alokacji pamieci\n");
		free(str1);
		free(str2);
		return 3;
	}
	printf("wynik: %s\n", str3);
	free(str1);
	free(str2);
	free(str3);

	return 0;
}

char* my_strcat(char *str1, char *str2)
{
	if(str1==NULL || str2==NULL) return NULL;
	int l1=strlen(str1);
	int l2=strlen(str2);
	char *str3=(char*)malloc(l1+l2+1);
	if(str3==NULL) return NULL;
	for(int i=0;i<l1;i++)
	{
		*(str3+i)=*(str1+i);
	}
	for(int i=0;;i++)
	{
		*(str3+l1+i)=*(str2+i);
		if(*(str2+i)=='\0') break;
	}
	return str3;
}
